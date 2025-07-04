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
