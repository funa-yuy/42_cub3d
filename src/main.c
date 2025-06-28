/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:44:56 by mfunakos          #+#    #+#             */
/*   Updated: 2025/06/28 16:47:27 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	// else
		//todo: 移動のキー操作 handle_key_input(keycode, data);
	// todo: 移動後のレンダリング
	return (0);
}

void	cub3d_loop(t_data *data)
{
	// todo: 初期値のレンダリング
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
