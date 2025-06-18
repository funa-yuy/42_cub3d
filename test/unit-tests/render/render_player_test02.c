#include "render.h"
#include "vec.h"

/// ```
/// make test test/unit-tests/render/render_player_test01.c
/// ```
int main()
{
	//
	//
	t_line_segment player_ray;

	player_ray = 
		(t_line_segment)
		{

			init_f32x4(0.000000, 4.500000, 3.500000, -1.570796),
			//init_f32x4(0.000000, 11.054022, -4.052800, -1.570796)
			init_f32x4(0.000000, 11.496656, -3.644704, -1.570796)
		};

	t_f32x4 cur_r;
	cur_r = cross_point((t_line_segment) {
		init_f32x4(0.000000, 5.000000, 1.000000, 0.000000),
		init_f32x4(0.000000, 5.000000, 2.000000, 0.000000)
	}, player_ray);

	print_f32x4("cross point",cur_r);
	cur_r = cross_point((t_line_segment) {
		init_f32x4(0.000000, 5.000000, 2.000000, 0.000000),
		init_f32x4(0.000000, 5.000000, 3.000000, 0.000000)
	}, player_ray);
	
	print_f32x4("cross point",cur_r);

	cur_r = cross_point((t_line_segment) {
		init_f32x4(0.000000, 5.000000, 3.000000, 0.000000),
		init_f32x4(0.000000, 5.000000, 4.000000, 0.000000)
	}, player_ray);

	print_f32x4("cross point",cur_r);
	return (0);
}
