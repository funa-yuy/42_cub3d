#include "vec.h"
#include <immintrin.h>

t_i32x4 init_i32x4(int w, int x, int y, int z)
{
	return (_mm_set_epi32(w, x, y, z));
}
