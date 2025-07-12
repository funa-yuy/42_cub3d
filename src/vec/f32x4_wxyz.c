/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f32x4_wxyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 08:08:17 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-12 08:08:17 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <emmintrin.h>
#include <immintrin.h>

// float [4]{w, x, y, z} <- t_f32x4(w, x, y, z)
void	set_f32x4_to_arr(float arr[4], t_f32x4 a)
{
	_mm_storeu_ps(arr, a);
}

float	f32x4_w(t_f32x4 a)
{
	float	arr[4];

	set_f32x4_to_arr(arr, a);
	return (arr[0]);
}

float	f32x4_x(t_f32x4 a)
{
	float	arr[4];

	set_f32x4_to_arr(arr, a);
	return (arr[1]);
}

float	f32x4_y(t_f32x4 a)
{
	float	arr[4];

	set_f32x4_to_arr(arr, a);
	return (arr[2]);
}

float	f32x4_z(t_f32x4 a)
{
	float	arr[4];

	set_f32x4_to_arr(arr, a);
	return (arr[3]);
}
