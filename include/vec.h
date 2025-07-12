/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 09:47:06 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-12 09:47:06 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

// for sse/avx header
# include <immintrin.h>
# include <stdbool.h>

typedef __m128					t_f32x4;
typedef __m128i					t_i32x4;

typedef struct s_vec_f32x4		t_vec_f32x4;
struct							s_vec_f32x4
{
	float						z;
	float						y;
	float						x;
	float						w;
};

typedef struct s_vec_i32x4		t_vec_i32x4;
struct							s_vec_i32x4
{
	int							z;
	int							y;
	int							x;
	int							w;
};

t_f32x4							init_f32x4(float w, float x, float y, float z);

t_i32x4							init_i32x4(int w, int x, int y, int z);

// instructions

// ## t_f32x4
t_f32x4							add_f32x4(t_f32x4 a, t_f32x4 b);

t_f32x4							sub_f32x4(t_f32x4 a, t_f32x4 b);

t_f32x4							mul_f32x4(t_f32x4 a, t_f32x4 b);

t_f32x4							div_f32x4(t_f32x4 a, t_f32x4 b);

float							norm_f32x4_pow(t_f32x4 a, t_f32x4 b);

t_f32x4							scalar_f32x4(t_f32x4 vec, float scalar);

// for 2d

bool							f32x4_has_error(t_f32x4 v);

// ## t_i32x4

void							set_f32x4_to_arr(float arr[4], t_f32x4 a);

void							set_i32x4_to_arr(int arr[4], t_i32x4 a);

t_vec_f32x4						f32x4_to_struct(t_f32x4 a);

// ## t_i32x4

t_vec_i32x4						i32x4_to_struct(t_i32x4 a);

// linear_solver

t_f32x4							linear_solver(t_f32x4 p, t_f32x4 q);

typedef struct s_line_segment	t_line_segment;
// cross point
t_f32x4							cross_point(t_line_segment a, t_line_segment b);

// debug function

void							print_f32x4(char *str, t_f32x4 a);

void							print_i32x4(char *str, t_i32x4 a);

bool							eq_f32x4(t_f32x4 a, t_f32x4 b);

bool							float_equal(float a, float b, float epsilon);

bool							float_less_equal(float a, float b,
									float epsilon);
#endif
