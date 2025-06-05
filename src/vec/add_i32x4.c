#include "vec.h"
#include <immintrin.h>


t_i32x4 add_i32x4(t_i32x4 a, t_i32x4 b)
{
	return (_mm_add_epi32(a, b));
}
