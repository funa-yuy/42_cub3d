#include "vec.h"

t_vec_f32x4 f32x4_to_struct(t_f32x4 a)
{
	float arr[4];

	set_f32x4_to_arr(arr, a);
	return ((t_vec_f32x4) {
		arr[0], arr[1], arr[2], arr[3]
	});
}
