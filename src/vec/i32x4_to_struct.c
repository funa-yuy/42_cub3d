#include "vec.h"
#include <immintrin.h>

t_vec_i32x4 i32x4_to_struct(t_i32x4 a)
{
	int arr[4];

	set_i32x4_to_arr(arr, a);
	return ((t_vec_i32x4) {
		arr[0], arr[1], arr[2], arr[3]
	});
}
