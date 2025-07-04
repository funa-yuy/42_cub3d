#ifndef FRAMES_H
# define FRAMES_H

# include "cub3d.h"
# include "line_segment.h"
# include <stdlib.h>

typedef struct s_axis_x_frames	t_axis_x_frames;

struct							s_axis_x_frames
{
	size_t						width;
	size_t						height;

	t_line_segment				*buf;
};

typedef struct s_axis_y_frames	t_axis_y_frames;
struct							s_axis_y_frames
{
	size_t						width;
	size_t						height;

	t_line_segment				*buf;
};

typedef struct s_axis_xy_frames	t_axis_xy_frames;
struct							s_axis_xy_frames
{
	t_axis_x_frames				*axis_x_frames;
	t_axis_y_frames				*axis_y_frames;
};

enum e_map_type					get_map_type(t_data *data, size_t x, size_t y);

typedef enum e_wall_type
{
	e_wall_type_no_img,
	e_wall_type_so_img,
	e_wall_type_we_img,
	e_wall_type_ea_img
}								t_wall_type;

typedef struct s_intersection_params
{
	t_f32x4						point;
	float						dist_sq;
	t_line_segment				*wall_segment_out;
}								t_intersection_params;

t_axis_x_frames					*init_axis_x_frames(t_data *data);

t_axis_y_frames					*init_axis_y_frames(t_data *data);

int								print_framex(t_axis_x_frames *f);

int								print_framey(t_axis_y_frames *f);

int								print_framexy(t_axis_x_frames *fx,
									t_axis_y_frames *fy);

bool							check_vec_up_or_down(t_line_segment l);

bool							check_vec_right_or_left(t_line_segment l);

bool							is_visible_surface_axis_x(t_line_segment l,
									t_f32x4 player);

bool							is_visible_surface_axis_y(t_line_segment l,
									t_f32x4 player);

t_wall_type						get_wall_type_by_line_segment(t_line_segment a);

void							*get_wall_img_by_wall_type_enum(t_data data,
									t_wall_type t);

int								print_line_segment(char *str,
									t_line_segment ls);

int								print_walls_line_segment_axis_y(\
		t_axis_y_frames *y_frames);

int								clear_axis_x_frames(t_axis_x_frames *frame_x);

int								clear_axis_y_frames(t_axis_y_frames *frame_y);

t_f32x4							get_cross_wall(t_axis_xy_frames walls,
									t_line_segment player_ray,
									t_line_segment *wall_line_segment);

#endif
