#include "cub3d.h"
#include "frames.h"
#include "vec.h"
#include <stdlib.h>

static t_line_segment	get_y_axis_segment(enum e_map_type pre_type,
		enum e_map_type cur_type, size_t x, size_t y)
{
	if (pre_type == EMPTY && cur_type == WALL)
		return ((t_line_segment){.s = init_f32x4(0, x, y, 0), .e = init_f32x4(0,
				x, y + 1, 0)});
	if (pre_type == WALL && cur_type == EMPTY)
		return ((t_line_segment){.s = init_f32x4(0, x, y + 1, 0),
			.e = init_f32x4(0, x, y, 0)});
	return ((t_line_segment){.s = init_f32x4(0, 0, 0, 0), .e = init_f32x4(0, 0,
			0, 0)});
}

t_axis_y_frames	*init_axis_y_frames(t_data *data)
{
	t_axis_y_frames	*f;
	size_t			x;
	size_t			y;
	enum e_map_type	pre_map_type;
	enum e_map_type	cur_map_type;

	f = malloc(sizeof(t_axis_y_frames));
	f->width = data->width + 1;
	f->height = data->height;
	f->buf = get_line_segment_arr(f->width, f->height);
	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			pre_map_type = get_map_type(data, x - 1, y);
			cur_map_type = get_map_type(data, x, y);
			f->buf[f->width * y + x] = get_y_axis_segment(pre_map_type,
					cur_map_type, x, y);
			x += 1;
		}
		y += 1;
	}
	return (f);
}
