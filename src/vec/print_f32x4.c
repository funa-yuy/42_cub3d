#include "vec.h"
#include "cub3d.h"

#include <immintrin.h>
#include <unistd.h>
#include <xmmintrin.h>


void print_f32x4(char *str, t_f32x4 a)
{
	float arr[4];

	set_f32x4_to_arr(arr, a);
	debug_dprintf(STDERR_FILENO, "%s", str);
	debug_dprintf(STDERR_FILENO, "f32x4(%f, %f, %f, %f)\n",
			arr[0], arr[1], arr[2], arr[3]);
}
