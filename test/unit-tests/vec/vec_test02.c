#include "vec.h"
#include  "line_segment.h"

/// ```
/// make test test/unit-tests/vec/vec_test02.c
/// ```
int main()
{
	t_f32x4 a;
	t_f32x4 b;
	t_f32x4 c;
	t_f32x4 d;

	t_f32x4 p;

	a = init_f32x4(0, 0, 0, 0);
	b = init_f32x4(0, 1, 1, 0);
	c = init_f32x4(0, 1, 0, 0);
	d = init_f32x4(0, 0, 1, 0);
	p = cross_point(
		(t_line_segment) {
			.s=a,
			.e=b
		},
		(t_line_segment) {
			.s=c,
			.e=d
		}
	);
	print_f32x4("cross point", p);
	return (0);
}
