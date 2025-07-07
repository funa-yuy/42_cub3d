/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cross_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 09:51:13 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-07 09:51:13 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frames.h"
#include "line_segment.h"
#include "render.h"
#include "vec.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

static void	update_intersection_if_closer(
	t_line_segment wall,
	t_line_segment player_ray,
	t_intersection_params *intersection
)
{
	t_f32x4	cur_r;
	float	cur_d;

	if (is_zero_vector(wall))
		return ;
	cur_r = cross_point(wall, player_ray);
	if (f32x4_has_error(cur_r))
		return ;
	cur_d = norm_f32x4_pow(cur_r, player_ray.s);
	if (f32x4_has_error(intersection->point) || cur_d < intersection->dist_sq)
	{
		intersection->point = cur_r;
		intersection->dist_sq = cur_d;
		*intersection->wall_segment_out = wall;
	}
}

static void	find_closest_in_buffer(
	t_line_segment *wall_buf,
	size_t wall_count,
	t_line_segment player_ray,
	t_intersection_params *intersection
)
{
	size_t	i;

	i = 0;
	while (i < wall_count)
	{
		update_intersection_if_closer(
			wall_buf[i],
			player_ray,
			intersection
			);
		i += 1;
	}
}

t_f32x4	get_cross_wall(t_axis_xy_frames walls, t_line_segment player_ray,
		t_line_segment *wall_line_segment)
{
	t_intersection_params	intersection;

	intersection.point = init_f32x4(1, 0, 0, 0);
	intersection.dist_sq = 0;
	intersection.wall_segment_out = wall_line_segment;
	find_closest_in_buffer(walls.axis_x_frames->buf, walls.axis_x_frames->width
		* walls.axis_x_frames->height, player_ray, &intersection);
	find_closest_in_buffer(walls.axis_y_frames->buf, walls.axis_y_frames->width
		* walls.axis_y_frames->height, player_ray, &intersection);
	return (intersection.point);
}
