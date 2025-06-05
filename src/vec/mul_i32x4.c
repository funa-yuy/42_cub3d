#include "vec.h"
#include <immintrin.h>

t_i32x4 mul_i32x4(t_i32x4 a, t_i32x4 b)
{
	return (_mm_mul_epi32(a, b));
}
