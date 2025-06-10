#include "frames.h"
#include <stdlib.h>

static 
int show(t_data	*target)
{	
	t_axis_x_frames *fx;
	t_axis_y_frames *fy;

	fx = init_axis_x_frames(target);
	print_framex(fx);
	fy = init_axis_y_frames(target);
	print_framey(fy);
	return (0);
}

/// ```bash
/// make test test/unit-tests/frame/frame_test02.c
/// ```
int main()
{
	t_data	*target;

	enum e_map_type	map[] = \
	{
		NOTHING, NOTHING, WALL, WALL, WALL, WALL, WALL, WALL, WALL, \
		WALL, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, NOTHING,\
		WALL, WALL, WALL, WALL, WALL, WALL, WALL, NOTHING, NOTHING,\
	};
	target = &(t_data){\
		NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		NULL,0x5A080A, 0x00F40B, /* f_color, c_color */\
		3, 9, /* height,width */\
		(t_pos){1, 4, DIR_SOUTH}, map};/*player, map*/
	show(target);
	return (0);
}
