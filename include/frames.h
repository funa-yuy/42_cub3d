#ifndef FRAMES_H
#define FRAMES_H

#include "line_segment.h"
#include <stdlib.h>
#include "cub3d.h"

typedef struct s_axis_x_frames t_axis_x_frames;

struct s_axis_x_frames
{
	size_t width;
	size_t height;

	t_line_segment *buf; // 配列
};

typedef struct s_axis_y_frames t_axis_y_frames;
struct s_axis_y_frames
{
	size_t width;
	size_t height;

	t_line_segment *buf; // 配列
};

enum e_map_type get_map_type(
	t_data *data,
	size_t x,
	size_t y
);

t_axis_x_frames *init_axis_x_frames(t_data *data);

t_axis_y_frames *init_axis_y_frames(t_data *data);

int print_framex(t_axis_x_frames *f);

int print_framey(t_axis_y_frames *f);

int print_framexy(t_axis_x_frames *fx, t_axis_y_frames *fy);

bool check_vec_up_or_down(t_line_segment l);

bool check_vec_right_or_left(t_line_segment l);

#endif
