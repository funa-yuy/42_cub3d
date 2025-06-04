#include "frames.h"
#include <stdlib.h>

/// ```bash
/// make test test/unit-tests/frame/frame_test00.c
/// ```
int main()
{
	t_axis_x_frames *fx;

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
		0xDC6400, 0xE11E00, /* f_color, c_color */\
		5, 6, /* height,width */\
		(t_pos){3, 4, DIR_NORTH}, map};/*player, map*/

	fx = init_axis_x_frames(target);
	print_framex(fx);
	return (0);
}
