#include "frames.h"
#include "line_segment.h"
#include "vec.h"

#include <stdbool.h>

bool is_visible_surface_axis_y(t_line_segment l, t_f32x4 player)
{
	if (is_zero_vector(l))
		return (false);
	else if (check_vec_up_or_down(l))
		return (f32x4_to_struct(l.s).x < f32x4_to_struct(player).x);
	else
		return (f32x4_to_struct(l.s).x > f32x4_to_struct(player).x);
}

bool is_visible_surface_axis_x(t_line_segment l, t_f32x4 player)
{
	if (is_zero_vector(l))
		return (false);
	else if (check_vec_right_or_left(l))
		return (f32x4_to_struct(l.s).y < f32x4_to_struct(player).y);
	else 
		return (f32x4_to_struct(l.s).y > f32x4_to_struct(player).y);
}
