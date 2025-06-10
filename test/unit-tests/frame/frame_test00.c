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
/// make test test/unit-tests/frame/frame_test00.c
/// ```
int main()
{
	t_data	*target;

	enum e_map_type	map[] = \
	{
		WALL, WALL, WALL, WALL, WALL, WALL, \
		WALL, EMPTY, EMPTY, WALL, EMPTY, WALL, \
		WALL, EMPTY, WALL, EMPTY, EMPTY, WALL, \
		WALL, WALL, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, WALL, WALL, WALL, WALL, WALL \
	};
	target = &(t_data){\
		NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		NULL,0xDC6400, 0xE11E00, /* f_color, c_color */\
		5, 6, /* height,width */\
		(t_pos){3, 4, DIR_NORTH}, map};/*player, map*/

	show(target);
	return (0);
}
