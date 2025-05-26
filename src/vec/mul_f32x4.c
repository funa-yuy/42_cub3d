#include "vec.h"
#include <immintrin.h>

t_f32x4 mul_f32x4(t_f32x4 a, t_f32x4 b)
{
	t_f32x4 r;

	r = _mm_mul_ps(a, b);
	return (r);
}

