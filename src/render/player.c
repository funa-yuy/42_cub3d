#include "cub3d.h"
#include "frames.h"
#include "line_segment.h"
#include "vec.h"
#include "render.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/// 返り値は、交点座標
t_f32x4 get_cross_wall(
	t_axis_xy_frames walls,            // 交わる可能性のある壁ベクトルの集合
	t_line_segment player_ray,         // playerからの視線ベクトル
	t_line_segment *wall_line_segment  // 交わった壁のベクトルがここに格納される
)
{
	t_f32x4 r;
	t_f32x4 cur_r;
	size_t t;
	float cur_d;
	float d;

	t = 0;
	r = init_f32x4(1, 0, 0, 0);
	// 交点がよりplayer_rayに近ければforgroundを更新する
	while (t < walls.axis_x_frames->height * walls.axis_x_frames->width)
	{
		if (is_zero_vector(walls.axis_x_frames->buf[t]))
		{
			t += 1;
			continue;
		}
		cur_r = cross_point(walls.axis_x_frames->buf[t], player_ray);
		cur_d = norm_f32x4_pow(cur_r, player_ray.s);
		if (f32x4_has_error(cur_r))
		{}
		else if (f32x4_has_error(r) || cur_d < d)
		{
			r = cur_r;
			d = cur_d;
			*wall_line_segment = walls.axis_x_frames->buf[t];
		}
		t += 1;
	}
	t = 0;
	while (t < walls.axis_y_frames->height * walls.axis_y_frames->width)
	{
		if (is_zero_vector(walls.axis_y_frames->buf[t]))
		{
			t += 1;
			continue;
		}
		cur_r = cross_point(walls.axis_y_frames->buf[t], player_ray);
		cur_d = norm_f32x4_pow(cur_r, player_ray.s);
		if (f32x4_has_error(cur_r))
		{}
		else if (f32x4_has_error(r) || cur_d < d)
		{
			r = cur_r;
			d = cur_d;
			*wall_line_segment = walls.axis_y_frames->buf[t];
		}
		t += 1;
	}
	return (r);
}

int
calc_screen_wall_height(int ratio, float distance, float angle)
{
	return (ratio / (distance * cosf(angle)));
	//(void) angle;
	//return (ratio / (distance));
}

int
calc_img_index(t_line_segment wall, t_f32x4 xos_point)
{
	float a = sqrtf(norm_f32x4_pow(wall.s, xos_point));
	int r = (int)floorf(IMG_SIZE * a);
	return (r);
}

/// 書くべき線を返却する
t_fence
get_line_to_be_drawn(
	t_data *data,
	t_axis_xy_frames frames,
	t_line_segment player_ray,
	float angle
)
{
	t_line_segment wall_seg;
	t_f32x4 c_p;
	int height;
	uint32_t *wall;

	c_p = get_cross_wall(frames, player_ray, &wall_seg);
	if (f32x4_has_error(c_p))
	{
		debug_dprintf(STDERR_FILENO, "has error\n");
		print_f32x4("\e[31mwall   s |\e[0m", wall_seg.s);
		print_f32x4("\e[31mwall   e |\e[0m", wall_seg.e);
		print_f32x4("\e[31mxos_point|\e[0m", c_p);
		print_f32x4("\e[31mplayer s |\e[0m", player_ray.s);
		print_f32x4("\e[31mplayer e |\e[0m", player_ray.e);
		debug_dprintf(STDERR_FILENO, "\e[31mERROR\e[0m\n");
		return ((t_fence) {.buf = NULL, .height=0}); 
	}
	height = calc_screen_wall_height(200, sqrtf(norm_f32x4_pow(c_p, player_ray.s)), angle);

	wall = get_wall_img_by_wall_type_enum(*data, get_wall_type_by_line_segment(wall_seg)); // ベクトルの向きから判定される、どの壁か

	//print_f32x4("wall   s |", wall_seg.s);
	//print_f32x4("wall   e |", wall_seg.e);
	//print_f32x4("xos_point|", c_p);
	//print_f32x4("player s |", player_ray.s);
	//print_f32x4("player e |", player_ray.e);

	int index = calc_img_index(wall_seg, c_p); // 壁のベクトルからみた交点のx座標
	//debug_dprintf(STDERR_FILENO, "index %d\n", index);
	return ((t_fence) {
		.buf = get_vertical_arr_n(
			wall,
			index,
			(t_vec_i32x4){0, IMG_SIZE, IMG_SIZE, 0}, // 画像の元情報
			height
		),
		.height=height
	});
}

/// playerからrayを出す。
/// axis_x_frames
int render_wall_to_screen(
	t_data *data,
       	t_axis_xy_frames axis_xy_frames,
	t_f32x4 player                   // t_f32x4(reserved , player_x, player_y, player_angle)
)
{
	t_vec_f32x4 player_vec;
	t_line_segment player_ray;
	float angle;
	float angle_step;
	int i;

	// 角視野120度
	player_vec = f32x4_to_struct(player);
	angle = - (M_PI/4);
	angle_step = ((M_PI/4) * 2)/ 600.0f; // 600.0f: step
				             // 120.0f: player view angle
	i = 0;
	while (i < 600)
	{
		t_fence arr;

		player_ray = (t_line_segment) {
			.s=player,
			.e=add_f32x4(
				player,
				scalar_f32x4(init_f32x4(
					0,
					cosf(player_vec.z + angle),
					sinf(player_vec.z + angle), 0),
					10.0f))};
		arr = get_line_to_be_drawn(data, axis_xy_frames, player_ray, angle);
		if (draw_vertical_line(
			data->mlx_addr,
			(t_vec_i32x4){0, 300 - arr.height / 2, 0 + i, 0},
			arr.buf,
			arr.height
		))
		{
			printf("\e[31mERROR!\e[0m\n");
		}
		free(arr.buf);
		i += 1;
		angle += angle_step;
	}
	return (0);
}

