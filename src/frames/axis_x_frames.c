/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_x_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 08:04:55 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-12 08:04:55 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "frames.h"
#include "vec.h"
#include <stdlib.h>
#include <unistd.h>

static t_line_segment	get_x_axis_segment(enum e_map_type pre_type,
		enum e_map_type cur_type, size_t x, size_t y)
{
	if (pre_type == EMPTY && cur_type == WALL)
		return ((t_line_segment){.s = init_f32x4(0, x + 1, y, 0),
			.e = init_f32x4(0, x, y, 0)});
	if (pre_type == WALL && cur_type == EMPTY)
		return ((t_line_segment){.s = init_f32x4(0, x, y, 0), .e = init_f32x4(0,
				x + 1, y, 0)});
	return ((t_line_segment){.s = init_f32x4(0, 0, 0, 0), .e = init_f32x4(0, 0,
			0, 0)});
}

t_axis_x_frames	*init_axis_x_frames(t_data *data)
{
	t_axis_x_frames	*f;
	size_t			x;
	size_t			y;
	enum e_map_type	pre_map_type;
	enum e_map_type	cur_map_type;

	f = malloc(sizeof(t_axis_x_frames));
	f->width = data->width;
	f->height = data->height + 1;
	f->buf = get_line_segment_arr(f->width, f->height);
	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			pre_map_type = get_map_type(data, x, y - 1);
			cur_map_type = get_map_type(data, x, y);
			f->buf[f->width * y + x] = get_x_axis_segment(pre_map_type,
					cur_map_type, x, y);
			x += 1;
		}
		y += 1;
	}
	return (f);
}
