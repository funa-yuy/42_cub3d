#include "vec.h"

int main()
{
	t_i32x4 a;
	t_i32x4 b;
	t_vec_i32x4 vc;

	a = init_i32x4(1, 2, 3, 4);
	b = init_i32x4(4, 3, 2, 1);

	print_i32x4("vec_a", a);
	print_i32x4("vec_b", b);
	debug_dprintf(STDERR_FILENO, "Ok!\n");

	print_i32x4("vec_a + b", add_i32x4(a, b));
	return (0);
}
