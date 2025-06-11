#include "vec.h"
#include "line_segment.h"

static t_vec_f32x4 minmax_line_segment_x(t_line_segment a)
{
	t_vec_f32x4 s;
	t_vec_f32x4 e;

	s = f32x4_to_struct(a.s);
	e = f32x4_to_struct(a.e);
	if (s.x < e.x)
		return (f32x4_to_struct(init_f32x4(s.x, 0, 0, e.x)));
	else
		return (f32x4_to_struct(init_f32x4(e.x, 0, 0, s.x)));
}

static t_vec_f32x4 minmax_line_segment_y(t_line_segment a)
{
	t_vec_f32x4 s;
	t_vec_f32x4 e;

	s = f32x4_to_struct(a.s);
	e = f32x4_to_struct(a.e);
	if (s.y < e.y)
		return (f32x4_to_struct(init_f32x4(s.y, 0, 0, e.y)));
	else
		return (f32x4_to_struct(init_f32x4(e.y, 0, 0, s.y)));
}

static t_f32x4 get_linear_equation_from_line_segment(t_line_segment a)
{
	t_vec_f32x4 a_start;
	t_vec_f32x4 a_end;

	a_start = f32x4_to_struct(a.s);
	a_end = f32x4_to_struct(a.e);
	return (init_f32x4(
	       0,
	       a_end.y - a_start.y,
	       a_start.x - a_end.x,
	       a_start.x * a_end.y - a_end.x*a_start.y)
	);
}

static bool cross_point_in_of_range(t_f32x4 p, t_line_segment l)
{
	t_vec_f32x4 x_axis_minmax;
	t_vec_f32x4 y_axis_minmax;
	t_vec_f32x4 point;

	x_axis_minmax = minmax_line_segment_x(l);
	y_axis_minmax = minmax_line_segment_y(l);
	point = f32x4_to_struct(p);
	return (
		(x_axis_minmax.w <= point.x && point.x <= x_axis_minmax.z) &&
		(y_axis_minmax.w <= point.y && point.y <= y_axis_minmax.z));
}

/// if parameter position out of range or each line segment is relation with pararel,
/// parameter w is set 1
t_f32x4 cross_point(t_line_segment a, t_line_segment b)
{
	t_f32x4 c;
	t_vec_f32x4 s;

	c = linear_solver(
		get_linear_equation_from_line_segment(a),
		get_linear_equation_from_line_segment(b));
	s = f32x4_to_struct(c);
	if (s.w == 1)
		return (c);
	if (cross_point_in_of_range(c, a) && cross_point_in_of_range(c, b))
		return (c);
	return (init_f32x4(1, 0, 0, 0));
}
