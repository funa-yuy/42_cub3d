#include "frames.h"
#include <stdlib.h>

static 
int show(t_data	*target)
{	
	t_axis_x_frames *fx;
	t_axis_y_frames *fy;

	fx = init_axis_x_frames(target);
	fy = init_axis_y_frames(target);
	print_framexy(fx, fy);
	return (0);
}

/// ```bash
/// make test test/unit-tests/frame/frame_test04.c
/// ```
int main()
{
	t_data	*target;
	target = init_cubdata("map/correct/room1.cub");

	show(target);
	return (0);
}
