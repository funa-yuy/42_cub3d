#include "frames.h"
#include <unistd.h>

static 
int show(t_data	*target)
{	
	t_axis_x_frames *fx;
	t_axis_y_frames *fy;

	fx = init_axis_x_frames(target);
	fy = init_axis_y_frames(target);
	print_framexy(fx, fy);

	print_walls_line_segment_axis_y(fy);
	return (0);
}

/// ```bash
/// make test test/unit-tests/frame/frame_test04.c
/// ```
int main()
{
	t_data	*target;
	target = init_cubdata("map/correct/simple.cub");

	show(target);
	return (0);
}
