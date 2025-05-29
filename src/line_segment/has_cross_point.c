// render.c
//
//
#include "line_segment.h"
#include "vec.h"
#include <stdbool.h>

// 一つの線分に関して
// x成分の大きい方を返す
// return (.w = min, 0, 0, .z = max)
t_vec_f32x4 minmax_line_segment_x(t_line_segment a)
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

t_vec_f32x4 minmax_line_segment_y(t_line_segment a)
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

static bool
has_cross_point_axis_x(t_line_segment a, t_line_segment b)
{
	t_vec_f32x4 a_min_max;
	t_vec_f32x4 b_min_max;

	a_min_max = minmax_line_segment_x(a);
	b_min_max = minmax_line_segment_x(b);
	return (
		a_min_max.w <= b_min_max.z && b_min_max.w < a_min_max.z
	);
}

static bool
has_cross_point_axis_y(t_line_segment a, t_line_segment b)
{
	t_vec_f32x4 a_min_max;
	t_vec_f32x4 b_min_max;

	a_min_max = minmax_line_segment_y(a);
	b_min_max = minmax_line_segment_y(b);
	return (
		a_min_max.w <= b_min_max.z && b_min_max.w < a_min_max.z
	);
}

// check t_line
// 線分同士が交わるかどうかを判定する関数
bool has_cross_point(t_line_segment a, t_line_segment b)
{
	return (
		has_cross_point_axis_x(a, b) || has_cross_point_axis_y(a, b)
	);
}
