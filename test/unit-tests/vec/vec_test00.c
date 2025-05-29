#include "vec.h"

#include <assert.h>


/// how to access each elements of vector
///
/// ```
/// make test test/unit-tests/vec/vec_test00.c
/// ```
int main()
{
	t_f32x4 a;
	t_f32x4 b;
	t_vec_f32x4 *vc;
	float arr[4];

	a = init_f32x4(1.0f, 2.0f, 3.0f, 4.0f);
	b = init_f32x4(4.0f, 3.0f , 2.0f, 1.0f);
	set_f32x4_to_arr(arr, a);
	vc = (t_vec_f32x4 *) arr;

	assert(
		vc->w == 1.0f && \
		vc->x == 2.0f && \
		vc->y == 3.0f && \
		vc->z == 4.0f
	);
	set_f32x4_to_arr(arr, b);
	vc = (t_vec_f32x4 *) arr;
	assert(
		vc->w == 4.0f && \
		vc->x == 3.0f && \
		vc->y == 2.0f && \
		vc->z == 1.0f
	);
	return (0);
}
