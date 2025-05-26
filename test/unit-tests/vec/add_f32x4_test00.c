#include "vec.h"
#include <stdio.h>

#include <unistd.h>

/// ```
/// make test test/unit_tests/vec/add_f32x4_test00.c
/// ```
int main()
{
	t_f32x4 a;
	t_f32x4 b;
	
	a= init_f32x4(1, 2, 3, 4);
	b = init_f32x4(4, 3 , 2, 1);
	print_f32x4("vec     a:", a);
	print_f32x4("vec     b:", b);
	print_f32x4("vec a + b:", add_f32x4(a, b));
	printf("(5, 5, 5, 5) == a + b %b \n",
		eq_f32x4(
			add_f32x4(a, b),
			init_f32x4(5.0f,5.0f, 5.0f, 5.0f)
		)
	);
	return (0);
}
