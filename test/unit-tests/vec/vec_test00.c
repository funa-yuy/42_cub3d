#include "vec.h"
#include "cub3d.h"

#include <assert.h>
#include <unistd.h>


/// how to access each elements of vector
///
/// ```
/// make test test/unit-tests/vec/vec_test00.c
/// ```
int main()
{
	t_f32x4 a;
	t_f32x4 b;
	t_vec_f32x4 vc;

	a = init_f32x4(1.0f, 2.0f, 3.0f, 4.0f);
	b = init_f32x4(4.0f, 3.0f , 2.0f, 1.0f);
	vc = f32x4_to_struct(a);

	assert(
		vc.w == 1.0f && \
		vc.x == 2.0f && \
		vc.y == 3.0f && \
		vc.z == 4.0f
	);
	vc = f32x4_to_struct(b);
	assert(
		vc.w == 4.0f && \
		vc.x == 3.0f && \
		vc.y == 2.0f && \
		vc.z == 1.0f
	);
	debug_dprintf(STDERR_FILENO, "Ok!\n");
	return (0);
}
