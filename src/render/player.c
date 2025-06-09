#include "cub3d.h"
#include "frames.h"
#include "vec.h"
#include "render.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

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
		cur_r = cross_point(walls.axis_x_frames->buf[t], player_ray);
		cur_d = norm_f32x4_pow(cur_r, player_ray.s);
		if (cur_d < d)
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
		cur_r = cross_point(walls.axis_y_frames->buf[t], player_ray);
		cur_d = norm_f32x4_pow(cur_r, player_ray.s);
		if (cur_d < d)
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
calc_screen_wall_height(int ratio, int distance, float angle)
{
	return (ratio/(distance * cosf(angle)));
}

int
calc_img_index(t_line_segment wall, t_f32x4 xos_point)
{
	return ((int)floorf(sqrtf(norm_f32x4_pow(wall.s, xos_point))));
}


/// 書くべき線を返却する
uint32_t *
get_line_to_be_drawn(
	t_data data,
	t_axis_xy_frames frames,
	t_line_segment player_ray,
	float angle
)
{
	t_line_segment seg;
	t_f32x4 c_p;

	c_p = get_cross_wall(frames, player_ray, &seg);
	return (get_vertical_arr_n(
		get_wall_img_by_wall_type_enum(data, get_wall_type_by_line_segment(seg)), // ベクトルの向きから判定される、どの壁か
		calc_img_index(seg, c_p), // 壁のベクトルからみた交点のx座標
		(t_vec_i32x4){0, IMG_SIZE, IMG_SIZE, 0}, // 画像の元情報
		calc_screen_wall_height(100, sqrtf(norm_f32x4_pow(c_p, player_ray.s)), angle)
	));
}

/// playerからrayを出す。
/// axis_x_frames
int render_wall_to_screen(
	t_data data,
       	t_axis_xy_frames axis_xy_frames,
	t_f32x4 player
)
{
	// 角視野120度
	return (0);
}

