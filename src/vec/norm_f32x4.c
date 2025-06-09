#include "vec.h"

float norm_f32x4_pow(t_f32x4 a, t_f32x4 b)
{
	t_f32x4 t;
	t_vec_f32x4 r;

	t = sub_f32x4(a, b); // a.x - b.x
			     // a.y - b.y
	t = mul_f32x4(t, t);
	r = f32x4_to_struct(t);
	return (r.x + r.y);
}
