#include "render.h"
#include "frames.h"
#include "vec.h"
#include "cub3d.h"
#include <unistd.h>

/// ```
/// make test test/unit-tests/render/render_player_test00.c
/// ```
int main()
{
	//
	//
	t_f32x4 c_p;
	t_line_segment wall_seg;
	t_data	*data;			// <- 自作データ
	data = init_cubdata("map/correct/simple.cub");

	c_p = get_cross_wall(
			
		(t_axis_xy_frames) {
			.axis_x_frames=init_axis_x_frames(data),
			.axis_y_frames=init_axis_y_frames(data),
		},
		(t_line_segment)
		{
			init_f32x4(0.000000, 4.500000, 3.500000, -1.570796),
			init_f32x4(0.000000, 11.515337, -3.626362, -1.570796)
		},
		&wall_seg
	);

	print_f32x4("cross point",c_p);
	return (0);
}
