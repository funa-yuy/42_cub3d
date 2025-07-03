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

int
calc_screen_wall_height(int ratio, float distance, float angle)
{
	return (ratio / (distance * cosf(angle)));
}

int
calc_img_index(t_line_segment wall, t_f32x4 xos_point)
{
	float a = sqrtf(norm_f32x4_pow(wall.s, xos_point));
	int r = (int)floorf(IMG_SIZE * a);
	return (r);
}

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

	wall = get_wall_img_by_wall_type_enum(*data, get_wall_type_by_line_segment(wall_seg));
	int index = calc_img_index(wall_seg, c_p);
	return ((t_fence) {
		.buf = get_vertical_arr_n(
			wall,
			index,
			(t_vec_i32x4){0, IMG_SIZE, IMG_SIZE, 0},
			height
		),
		.height=height
	});
}

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

