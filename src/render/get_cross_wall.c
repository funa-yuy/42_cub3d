#include "frames.h"
#include "line_segment.h"
#include "vec.h"
#include "render.h"

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Structure that stores the intersection detection results.
 * @param point Coordinates of the nearest intersection.
 * @param dist_sq Square of the distance from the player's viewpoint to the intersection.
 * @param wall_segment Pointer to the destination that stores the intersecting wall segment.
 */
typedef struct s_intersection_params
{
	t_f32x4		point;
	float		dist_sq;
	t_line_segment	*wall_segment_out;
}	t_intersection_params;

/**
 * @brief Search for the closest intersection point with the ray from the wall line array.
 * @param wall_buf Wall line array to be searched.
 * @param wall_count Number of elements in the array.
 * @param player_ray Player's ray.
 * @param intersection Pointer to store and update the nearest intersection information.
 */
static void	find_closest_in_buffer(
	t_line_segment *wall_buf,
	size_t wall_count,
	t_line_segment player_ray,
	t_intersection_params *intersection
)
{
	size_t	i;
	t_f32x4	cur_r;
	float	cur_d;

	i = 0;
	while (i < wall_count)
	{
		if (is_zero_vector(wall_buf[i]))
		{
			i += 1;
			continue;
		}
		cur_r = cross_point(wall_buf[i], player_ray);
		if (f32x4_has_error(cur_r))
		{
			i += 1;
			continue;
		}
		cur_d = norm_f32x4_pow(cur_r, player_ray.s);
		if (f32x4_has_error(intersection->point) || cur_d < intersection->dist_sq)
		{
			intersection->point = cur_r;
			intersection->dist_sq = cur_d;
			*intersection->wall_segment_out = wall_buf[i];
		}
		i += 1;
	}
}

/**
 * @brief Find the point of intersection closest to the player's ray among all walls.
 * @param walls A group of wall frames along the X-axis and Y-axis.
 * @param player_ray The player's ray.
 * @param wall_line_segment [out] A pointer that stores the intersecting wall line segment.
 * @return The coordinates of the closest intersection point. If none is found, an error value is returned.
 */
t_f32x4 get_cross_wall(
	t_axis_xy_frames walls,
	t_line_segment player_ray,
	t_line_segment *wall_line_segment
)
{
	t_intersection_params	intersection;

	intersection.point = init_f32x4(1, 0, 0, 0);
	intersection.dist_sq = 0;
	intersection.wall_segment_out = wall_line_segment;
	find_closest_in_buffer(
		walls.axis_x_frames->buf,
		walls.axis_x_frames->width * walls.axis_x_frames->height,
		player_ray,
		&intersection);
	find_closest_in_buffer(
		walls.axis_y_frames->buf,
		walls.axis_y_frames->width * walls.axis_y_frames->height,
		player_ray,
		&intersection);
	return (intersection.point);
}
