#include "cub3d.h"
#include "frames.h"
#include "line_segment.h"
#include "render.h"
#include "vec.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	calc_screen_wall_height(int ratio, float distance, float angle)
{
	return (ratio / (distance * cosf(angle)));
}

int	calc_img_index(t_line_segment wall, t_f32x4 xos_point)
{
	float	a;
	int		r;

	a = sqrtf(norm_f32x4_pow(wall.s, xos_point));
	r = (int)floorf(IMG_SIZE * a);
	return (r);
}

t_fence	get_line_to_be_drawn(t_data *data, t_axis_xy_frames frames,
		t_line_segment player_ray, float angle)
{
	t_line_segment	wall_seg;
	t_f32x4			c_p;
	int				height;
	uint32_t		*wall;
	int				index;

	c_p = get_cross_wall(frames, player_ray, &wall_seg);
	if (f32x4_has_error(c_p))
		return ((t_fence){.buf = NULL, .height = 0});
	height = calc_screen_wall_height(200, sqrtf(norm_f32x4_pow(c_p,
					player_ray.s)), angle);
	wall = get_wall_img_by_wall_type_enum(*data,
			get_wall_type_by_line_segment(wall_seg));
	index = calc_img_index(wall_seg, c_p);
	return ((t_fence){.buf = get_vertical_arr_n(wall, index, (t_vec_i32x4){0,
			IMG_SIZE, IMG_SIZE, 0}, height), .height = height});
}

int	render_wall_to_screen(t_data *data, t_axis_xy_frames axis_xy_frames,
		t_f32x4 player)
{
	t_vec_f32x4		player_vec;
	t_line_segment	player_ray;
	float			angle;
	int				i;
	t_fence			arr;

	player_vec = f32x4_to_struct(player);
	angle = -(M_PI / 6);
	i = 0;
	while (i < 600)
	{
		player_ray = (t_line_segment){.s = player, .e = add_f32x4(player,
				scalar_f32x4(init_f32x4(0, cosf(player_vec.z + angle),
						sinf(player_vec.z + angle), 0), 10.0f))};
		arr = get_line_to_be_drawn(data, axis_xy_frames, player_ray, angle);
		if (draw_vertical_line(data->mlx_addr, (t_vec_i32x4){0, 300 - arr.height
				/ 2, 0 + i, 0}, arr.buf, arr.height))
			debug_dprintf(STDERR_FILENO, "\e[31mERROR!\e[0m\n");
		free(arr.buf);
		i += 1;
		angle += ((M_PI / 6) * 2) / 600.0f;
	}
	return (0);
}
