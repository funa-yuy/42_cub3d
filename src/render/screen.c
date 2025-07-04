#include "cub3d.h"
#include "line_segment.h"
#include "vec.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

size_t	get_vertical_image_axis_x(t_line_segment axis_x_wall,
		t_f32x4 cross_point, int img_width)
{
	float	d;

	d = fabsf(f32x4_to_struct(axis_x_wall.s).x
			- f32x4_to_struct(cross_point).x);
	return ((size_t)floorf(d * (float)img_width));
}

size_t	get_vertical_image_axis_y(t_line_segment axis_y_wall,
		t_f32x4 cross_point, int img_width)
{
	float	d;

	d = f32x4_to_struct(axis_y_wall.s).y - f32x4_to_struct(cross_point).y;
	d = fabsf(d);
	return ((size_t)floorf(d * (float)img_width));
}

uint32_t	*get_vertical_arr_n(void *img_arr, int index, t_vec_i32x4 size,
		int out_size)
{
	uint32_t	*arr;
	int			i;
	float		d;

	arr = (uint32_t *)malloc(sizeof(uint32_t) * out_size);
	i = 0;
	d = (float)size.y / (float)out_size;
	while (i < out_size)
	{
		arr[i] = ((uint32_t *)img_arr)[size.x * (int)floorf(d * i) + index];
		i += 1;
	}
	return (arr);
}
