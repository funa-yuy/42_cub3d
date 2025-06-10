#include "frames.h"
#include "render.h"
#include "cub3d.h"
#include "vec.h"
#include <unistd.h>

bool	check_t_data_structure(t_data *target, t_data *test);

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
	data = init_cubdata("map/correct/simple.cub");

	//data->win = mlx_new_window(data->mlx, 600, 600, "title");

	debug_dprintf(STDERR_FILENO, "%p %p %p\n", &(data->mlx_addr), data->mlx_addr, *data->mlx_addr);
	debug_dprintf(STDERR_FILENO, "%p\n", data->no_img_addr);
	debug_dprintf(STDERR_FILENO, "%lx\n", data->mlx_addr);
	debug_dprintf(STDERR_FILENO, "%lx\n", data->no_img_addr);

	debug_dprintf(STDERR_FILENO, "x y = %d %d\n", data->player.x, data->player.y);
	render_wall_to_screen(
		data,
		(t_axis_xy_frames) {
			.axis_x_frames=init_axis_x_frames(data),
			.axis_y_frames=init_axis_y_frames(data),
		},
		init_f32x4(0, ((float)data->player.x) + 0.5f, ((float)data->player.y) + 0.5f, 0)
	);
	mlx_put_image_to_window(data->mlx, data->win, data -> mlx_img, 0, 0);
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
