#include "cub3d.h"
#include "vec.h"
#include "line_segment.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 
// resolution 
// angular
// 
// unsafe
size_t get_vertical_image_axis_x(t_line_segment axis_x_wall, t_f32x4 cross_point, int img_width)
{
	float d;

	d = f32x4_to_struct(axis_x_wall.s).x - f32x4_to_struct(cross_point).x; // -1 <= d < 1
	d = fabsf(d);
	return ((size_t) floorf(d * (float) img_width));
}

size_t get_vertical_image_axis_y(t_line_segment axis_y_wall, t_f32x4 cross_point, int img_width)
{
	float d;

	d = f32x4_to_struct(axis_y_wall.s).y - f32x4_to_struct(cross_point).y; // -1 <= d < 1
	d = fabsf(d); // 0 <= d < 1
	return ((size_t) floorf(d * (float) img_width));
}

// TODO:一回ポイントするごとにチェックが入るのは効率が悪い
void	put_point_only_check_y(
	uint32_t *mlx_addr,
	int32_t	x,
	int32_t	y,
	uint32_t color)
{
	if (0 <= y && y < WINDOW_HEIGHT)
	{
		mlx_addr[y * WINDOW_WIDTH + x] = color;
	}
}

/// 水平に書く
int draw_vertical_line(
	void *mlx_addr, // mut
	t_vec_i32x4 start, // スクリーン上で始点になるベクトル
	uint32_t vline[],
	size_t vline_len
)
{
	size_t i;

	i = 0;
	if (!(0 <= start.x && start.x < WINDOW_WIDTH))
		return (1);
	while (i < vline_len)
	{
		put_point_only_check_y(mlx_addr, start.x, start.y + i, vline[i]);
		i += 1;
	}
	return (0);
}
