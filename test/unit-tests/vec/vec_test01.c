#include "vec.h"

int test00()
{
	t_f32x4 a;
	t_f32x4 b;

	a = init_f32x4(0, 2, 8, 18);
	b = init_f32x4(0, 1, 1, 3);
	
	print_f32x4("linear_solver", linear_solver(a, b));
	return (0);
}

int test01()
{
	t_f32x4 a;
	t_f32x4 b;

	a = init_f32x4(0, 5, -5, 10);
	b = init_f32x4(0, 1, 10, 57);
	
	print_f32x4("linear_solver", linear_solver(a, b));
	return (0);
}



/// ```
/// make test test/unit-tests/vec/vec_test01.c
/// ```
int main()
{
	test00();
	test01();

}
