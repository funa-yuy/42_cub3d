#include "vec.h"
#include <stdbool.h>

bool	f32x4_has_error(t_f32x4 v)
{
	t_vec_f32x4	a;

	a = f32x4_to_struct(v);
	return (a.w == 1);
}
