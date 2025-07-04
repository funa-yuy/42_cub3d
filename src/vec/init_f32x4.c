#include "vec.h"
#include <immintrin.h>

t_f32x4	init_f32x4(float w, float x, float y, float z)
{
	return (_mm_set_ps(w, x, y, z));
}
