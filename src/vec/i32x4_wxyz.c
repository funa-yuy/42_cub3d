#include "vec.h"
#include <immintrin.h>


void set_i32x4_to_arr(int arr[4], t_i32x4 a)
{
	// _mm_storeu_epi32(arr, a);
	/* 校舎PCでは、_mm_storeu_epi32が使えないため、_mm_storeu_si128を使う*/
	_mm_storeu_si128((__m128i *)arr, a);
}
