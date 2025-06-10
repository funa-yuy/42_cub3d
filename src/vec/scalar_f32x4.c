#include "vec.h"
#include <immintrin.h>

// 4つのf32を含むベクトルにスカラー値を掛ける
t_f32x4 scalar_f32x4(t_f32x4 vec, float scalar) 
{
    return _mm_mul_ps(vec, _mm_set1_ps(scalar));
}
