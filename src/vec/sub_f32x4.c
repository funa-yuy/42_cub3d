#include "vec.h"
#include <immintrin.h>

t_f32x4	sub_f32x4(t_f32x4 a, t_f32x4 b)
{
	return (_mm_sub_ps(a, b));
}
