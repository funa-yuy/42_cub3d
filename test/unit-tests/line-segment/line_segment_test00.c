#include "line_segment.h"
#include "vec.h"
#include <stdio.h>

/// ```
///
/// make test test/unit-tests/line-segment/line_segment_test00.c
/// ```
int main()
{
	t_line_segment a;
	t_line_segment b;

	a.s = init_f32x4(0,0,0,0);
	a.e = init_f32x4(0,2,2,0);

	b.e = init_f32x4(0, 0, 4, 0);
	b.s = init_f32x4(0, 4, 0, 0);

	printf("has cross point %b \n", has_cross_point(a, b));
	return (0);
}

