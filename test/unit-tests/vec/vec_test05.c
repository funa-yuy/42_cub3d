#include "vec.h" 
#include "cub3d.h"
#include <unistd.h>

/// ```bash
/// make test test/unit-tests/vec/vec_test05.c
/// ```
int main()
{
	t_f32x4 a;
	t_f32x4 b;

	a = init_f32x4(0, 0, 0, 0);
	//b = init_f32x4(0, 3, 4, 0);
	b = init_f32x4(0, 6, 8, 0);

	debug_dprintf(STDERR_FILENO, "pow %f\n",
		norm_f32x4_pow(a, b)
	);
	return (0);
}
