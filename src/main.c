/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:44:56 by mfunakos          #+#    #+#             */
/*   Updated: 2025/06/28 15:38:28 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "move.h"
#include "render.h"

void	render_scene(t_data *data)
{
	ft_memset(data->mlx_addr, 0, \
			WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(uint32_t));
	render_wall_to_screen(\
		data, \
		(t_axis_xy_frames){\
			.axis_x_frames = init_axis_x_frames(data), \
			.axis_y_frames = init_axis_y_frames(data), \
		},
		init_f32x4(0, data->player.x, data->player.y, \
					data->player.angle));
	mlx_put_image_to_window(data->mlx, data->win, data->mlx_img, 0, 0);
}

int	close_window(t_data *data)
{
	free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	debug_dprintf(STDERR_FILENO, "キー入力: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W)
		update_position_front(data);
	else if (keycode == KEY_A)
		update_position_left(data);
	else if (keycode == KEY_S)
		update_position_back(data);
	else if (keycode == KEY_D)
		update_position_right(data);
	else if (keycode == KEY_LEFT)
		update_angle_left(data);
	else if (keycode == KEY_RIGHT)
		update_angle_right(data);
	// todo: 移動後の描画: render_scene(data);
	return (0);
}

void	cub3d_loop(t_data *data)
{
	// todo: 初期値の描画: render_scene(data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_key_hook(data->win, key_press, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Invalid number of arguments.\n", \
			ft_strlen("Invalid number of arguments.\n"));
		return (1);
	}
	data = init_cubdata(argv[1]);
	cub3d_loop(data);
	return (0);
}
