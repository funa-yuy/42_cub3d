#include "frames.h"
#include "render.h"
#include "cub3d.h"
#include "vec.h"
#include <unistd.h>
#include <math.h>

bool	check_t_data_structure(t_data *target, t_data *test);

int cross_hook(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

/*
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
111111
100101
101001
1100N1
111111
*/
int	init_test00(void)
{
	t_data	*data;			// <- 自作データ
	t_axis_xy_frames frame_xy;

	data = init_cubdata("map/correct/map_04.cub");
	frame_xy = (t_axis_xy_frames) {
			.axis_x_frames=init_axis_x_frames(data),
			.axis_y_frames=init_axis_y_frames(data),
		};
	render_wall_to_screen(
		data,
		frame_xy,
		init_f32x4(0, ((float)data->player.x) + 0.5f, ((float)data->player.y) + 0.5f,  -M_PI/2));
	mlx_put_image_to_window(data->mlx, data->win, data -> mlx_img, 0, 0);
	mlx_hook(data->win, DestroyNotify, NoEventMask, cross_hook, data);
	mlx_loop(data->mlx);
	debug_dprintf(STDERR_FILENO, "cub3d bye!\n");
	clear_axis_x_frames(frame_xy.axis_x_frames);
	clear_axis_y_frames(frame_xy.axis_y_frames);
	free_data(data);
	return (0);
}

/// ```bash
/// make test test/unit-tests/render/mlx_render_test04.c
/// ```
int	main(void)
{
	int	status;

	status = init_test00();
	return (status);
}
