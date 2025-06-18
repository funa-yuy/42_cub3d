#include "vec.h"
#include "cub3d.h"

#include <assert.h>
#include <unistd.h>


/// how to access each elements of vector
///
/// ```
/// make test test/unit-tests/vec/vec_test03.c
/// ```
int main()
{
	t_i32x4 a;
	t_i32x4 b;
	t_vec_i32x4 vc;

	a = init_i32x4(1, 2, 3, 4);
	b = init_i32x4(4, 3, 2, 1);
	vc = i32x4_to_struct(a);

	assert(
		vc.w == 1 && \
		vc.x == 2 && \
		vc.y == 3 && \
		vc.z == 4
	);
	vc = i32x4_to_struct(b);
	assert(
		vc.w == 4 && \
		vc.x == 3 && \
		vc.y == 2 && \
		vc.z == 1
	);
	debug_dprintf(STDERR_FILENO, "Ok!\n");
	return (0);
}
