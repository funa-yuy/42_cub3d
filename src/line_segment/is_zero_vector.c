#include "line_segment.h"
#include "vec.h"
#include <stdbool.h>

bool	is_zero_vector(t_line_segment a)
{
	return (eq_f32x4(a.e, a.s));
}
