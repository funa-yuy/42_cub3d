#include "cub3d.h"
#include "frames.h"
#include "vec.h"
#include <unistd.h>

#include <stdbool.h>

/// 上向きのときtrue
bool check_vec_up_or_down(t_line_segment l)
{
	t_vec_f32x4 a;

	a = f32x4_to_struct(
		sub_f32x4(l.s, l.e)
	);
	return (0 < a.y);
}

/// 右向きのときtrue
bool check_vec_right_or_left(t_line_segment l)
{
	t_vec_f32x4 a;

	a = f32x4_to_struct(
		sub_f32x4(l.s, l.e)
	);
	return (0 < a.x);
}

int print_framex(t_axis_x_frames *f)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			if (is_zero_vector(f->buf[y * f->width + x]))
				debug_dprintf(STDERR_FILENO, "__");
			else if (check_vec_right_or_left(f->buf[y * f->width + x]))
				debug_dprintf(STDERR_FILENO, "->");
			else 
				debug_dprintf(STDERR_FILENO, "<-");
			x += 1;
		}
		debug_dprintf(STDERR_FILENO, "\n");
		y += 1;
	}
	return (0);
}

int print_framey(t_axis_y_frames *f)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			if (is_zero_vector(f->buf[y * f->width + x]))
				debug_dprintf(STDERR_FILENO, "__");
			else if (check_vec_up_or_down(f->buf[y * f->width + x]))
				debug_dprintf(STDERR_FILENO, "^_");
			else 
				debug_dprintf(STDERR_FILENO, "_v");
			x += 1;
		}
		debug_dprintf(STDERR_FILENO, "\n");
		y += 1;
	}
	return (0);
}

int print_framexy(t_axis_x_frames *fx, t_axis_y_frames *fy)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (y < fy->height + fx->height)
	{
		x = 0;
		if (y % 2 == 1)
		{
			while (x < fy->width)
			{
				if (is_zero_vector(fy->buf[(y / 2) * fy->width + x]))
					debug_dprintf(STDERR_FILENO, "  ");
				else if (check_vec_up_or_down(fy->buf[(y / 2) * fy->width + x]))
					debug_dprintf(STDERR_FILENO, "^ ");
				else 
					debug_dprintf(STDERR_FILENO, " v");
				x += 1;
			}
		}
		else
		{
			debug_dprintf(STDERR_FILENO, " ");
			while (x < fx->width)
			{
				if (is_zero_vector(fx->buf[(y / 2) * fx->width + x]))
					debug_dprintf(STDERR_FILENO, "  ");
				else if (check_vec_right_or_left(fx->buf[(y / 2) * fx->width + x]))
					debug_dprintf(STDERR_FILENO, "->");
				else 
					debug_dprintf(STDERR_FILENO, "<-");
				x += 1;
			}
		}
		debug_dprintf(STDERR_FILENO, "\n");
		y += 1;
	}
	return (0);
}
