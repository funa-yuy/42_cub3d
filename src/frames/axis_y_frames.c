#include "frames.h"
#include "cub3d.h"
#include "vec.h"
#include <stdlib.h>

/// 範囲外にアクセスした場合には
/// wallを返却します
/// 
t_axis_y_frames *init_axis_y_frames(t_data *data)
{
	t_axis_y_frames *f;

	f = malloc(sizeof(t_axis_y_frames));
	f->width = data->width + 1;
	f->height = data->height;
	f->buf = get_line_segment_arr(f->width, f->height);
	size_t x;
	size_t y;

	enum e_map_type pre_map_type;
	enum e_map_type cur_map_type;

	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			cur_map_type = get_map_type(data, x, y);
			pre_map_type = get_map_type(data, x - 1, y);
			if (pre_map_type == EMPTY && cur_map_type == EMPTY)
				f->buf[f->width * y + x] = (t_line_segment) {
					init_f32x4(0, 0, 0, 0),
					init_f32x4(0, 0, 0, 0)};
			else if (pre_map_type == EMPTY && cur_map_type == WALL)
				f->buf[f->width * y + x] = (t_line_segment) {
					init_f32x4(0, x, y, 0),
					init_f32x4(0, x, y + 1, 0)};
			else if (pre_map_type == WALL && cur_map_type == EMPTY)
				f->buf[f->width * y + x] = (t_line_segment) {
					init_f32x4(0, x, y + 1, 0),
					init_f32x4(0, x, y, 0)};
			else
				f->buf[f->width * y + x] = (t_line_segment) {
					init_f32x4(0, 0, 0, 0),
					init_f32x4(0, 0, 0, 0)};
			x += 1;
		}
		y += 1;
	}
	return (f);
}
