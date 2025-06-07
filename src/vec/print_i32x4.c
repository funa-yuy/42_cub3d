#include "vec.h"
#include "cub3d.h"
#include <stdlib.h>

void print_i32x4(char *str, t_i32x4 a)
{
	t_vec_i32x4 p;

	p = i32x4_to_struct(a);
	debug_dprintf(STDERR_FILENO, "%s", str);
	debug_dprintf(STDERR_FILENO, "f32x4(%d, %d, %d, %d)\n",
			p.w, p.x, p.y, p.z);
}
