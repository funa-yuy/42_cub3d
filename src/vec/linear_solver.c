/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 09:52:54 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-07 09:52:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "line_segment.h"
#include "vec.h"

/// p:.x .y = [a, b]
/// q:.x .y = [c, d]
///
/// r:.x .y = [e, f]
///
/// offset = 0
/// ```
/// [
///     [a, b],
///     [c, d],
/// ] ->
///
///
/// [
///     [e, b],
///     [f, d],
/// ]
/// ```
///
/// offset = otherwise
/// ```
///
/// [
///     [a, b],
///     [c, d],
/// ] ->
///
///
/// [
///     [a, e],
///     [b, f],
/// ]
/// ```
static t_line_segment	matrix_2x2_mapper(t_f32x4 p, t_f32x4 q, t_f32x4 r,
		int offset)
{
	t_vec_f32x4	rs;

	rs = f32x4_to_struct(r);
	if (offset == 0)
		return ((t_line_segment){
			.s = add_f32x4(
				mul_f32x4(
					p, init_f32x4(
						0, 0, 1, 0)),
				init_f32x4(0, rs.x, 0, 0)),
			.e = add_f32x4(
				mul_f32x4(
					q, init_f32x4(
						0, 0, 1, 0)),
				init_f32x4(0, rs.y, 0, 0))});
	else
		return ((t_line_segment){
			.s = add_f32x4(
				mul_f32x4(
					p, init_f32x4(0, 1, 0, 0)),
				init_f32x4(0, 0, rs.x, 0)),
			.e = add_f32x4(
				mul_f32x4(
					q, init_f32x4(0, 1, 0, 0)),
				init_f32x4(0, 0, rs.y, 0))});
}

/// a:t_f32x4 .x .y
/// b:t_f32x4 .x .y
///
/// interpret as
/// A = [
///   [a.x, a.y],
///   [b.x, b.y],
/// ]
///
/// and then calc det(A)
static float	matrix_scalar_2x2(t_f32x4 a, t_f32x4 b)
{
	t_vec_f32x4	a_vec;
	t_vec_f32x4	b_vec;

	a_vec = f32x4_to_struct(a);
	b_vec = f32x4_to_struct(b);
	return (a_vec.x * b_vec.y - a_vec.y * b_vec.x);
}

/// p:.wxyz = [0, a, b, e]
/// q:.wxyz = [0, c, d, f]
///
/// interpret as
///
/// a*x + b*y = e
/// c*x + d*y = f
///
/// and solve this equations
///
///
/// if parameter positionj out of range or 
/// each line segment is relation with pararel,
/// parameter w is set 1
t_f32x4	linear_solver(t_f32x4 p, t_f32x4 q)
{
	float			base;
	t_line_segment	x_nume;
	t_line_segment	y_nume;

	base = matrix_scalar_2x2(p, q);
	if (base == 0)
		return (init_f32x4(1, 0, 0, 0));
	x_nume = matrix_2x2_mapper(p, q, init_f32x4(0, f32x4_to_struct(p).z,
				f32x4_to_struct(q).z, 0), 0);
	y_nume = matrix_2x2_mapper(p, q, init_f32x4(0, f32x4_to_struct(p).z,
				f32x4_to_struct(q).z, 0), 1);
	return (init_f32x4(0, matrix_scalar_2x2(x_nume.s, x_nume.e) / base,
			matrix_scalar_2x2(y_nume.s, y_nume.e) / base, 0));
}
