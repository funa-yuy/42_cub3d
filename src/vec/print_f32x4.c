#include "vec.h"
#include "cub3d.h"

#include <immintrin.h>
#include <unistd.h>
#include <xmmintrin.h>


void print_f32x4(char *str, t_f32x4 a)
{
	t_vec_f32x4 p;

	p = f32x4_to_struct(a);
	debug_dprintf(STDERR_FILENO, "%s", str);
	debug_dprintf(STDERR_FILENO, "f32x4(%f, %f, %f, %f)\n",
			p.w, p.x, p.y, p.z);
}
