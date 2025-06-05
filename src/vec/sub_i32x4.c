#include "vec.h"
#include <immintrin.h>

t_i32x4 sub_i32x4(t_i32x4 a, t_i32x4 b)
{
	return (_mm_sub_epi32(a, b));
}
