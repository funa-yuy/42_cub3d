#include "vec.h"
#include "cub3d.h"

#include <unistd.h>

int test00(
	t_f32x4 a,
	t_f32x4 b
)
{
	t_vec_f32x4 a_s;
	t_vec_f32x4 b_s;

	a_s = f32x4_to_struct(a);
	b_s = f32x4_to_struct(b);
	debug_dprintf(STDERR_FILENO, "%f*x + %f*y = %f\n", a_s.x, a_s.y, a_s.z);
	debug_dprintf(STDERR_FILENO, "%f*x + %f*y = %f\n", b_s.x, b_s.y, b_s.z);
	print_f32x4("linear_solver", linear_solver(a, b));
	return (0);
}


/// ```
/// make test test/unit-tests/vec/vec_test01.c
/// ```
int main()
{
	test00(
		init_f32x4(0, 2, 8, 18),
		init_f32x4(0, 1, 1, 3)
	);
	test00(
		init_f32x4(0, 5, -5, 10),
		init_f32x4(0, 1, 10, 57)
	);
}
