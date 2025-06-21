/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:31:41 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 15:49:24 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef DEBUG

void	degub_mlx_data(t_data *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	mlx_put_image_to_window(mlx, win, data->no_img, IMG_SIZE * 0, 0);
	mlx_put_image_to_window(mlx, win, data->so_img, IMG_SIZE * 1, 0);
	mlx_put_image_to_window(mlx, win, data->we_img, IMG_SIZE * 2, 0);
	mlx_put_image_to_window(mlx, win, data->ea_img, IMG_SIZE * 3, 0);
	mlx_loop(mlx);
}

char	*get_player_angle_str(float angle)
{
	const float	epsilon = 1e-6;

	if (fabs(angle - 3.0f * M_PI / 2.0f) < epsilon)
		return ("北");
	else if (fabs(angle - 0.0f) < epsilon)
		return ("東");
	else if (fabs(angle - M_PI / 2.0f) < epsilon)
		return ("南");
	else if (fabs(angle - M_PI) < epsilon)
		return ("西");
	return ("東西南北に当てはまりません");
}

void	print_map_data(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->width * data->height)
	{
		if (data->map[i] == EMPTY)
			debug_dprintf(STDOUT_FILENO, "0");
		else if (data->map[i] == WALL)
			debug_dprintf(STDOUT_FILENO, "1");
		else if (data->map[i] == NOTHING)
			debug_dprintf(STDOUT_FILENO, " ");
		else
			debug_dprintf(STDOUT_FILENO, "\x1b[31m*\x1b[31m");
		if ((i + 1) % data->width == 0)
			printf("\n");
		i++;
	}
}

void	debug_print_data(t_data *data)
{
	debug_dprintf(STDOUT_FILENO, "----------- パース後 -------------\n");
	debug_dprintf(STDOUT_FILENO, "MLX pointer: %p\n", data->mlx);
	debug_dprintf(STDOUT_FILENO, "WIN pointer: %p\n", data->win);
	debug_dprintf(STDOUT_FILENO, "MLX addr pointer: %p\n", data->mlx_addr);
	debug_dprintf(STDOUT_FILENO, "texture↓\n北 = %p\n南 = %p\n西= %p\n東 = %p\n", \
						data->no_img, data->so_img, data->we_img, data->ea_img);
	debug_dprintf(STDOUT_FILENO, "addr↓\n北 = %p\n南 = %p\n西= %p\n東 = %p\n", \
						data->no_img_addr, data->so_img_addr, \
						data->we_img_addr, data->ea_img_addr);
	debug_dprintf(STDOUT_FILENO, "床   color: 0x%06X\n", data->f_color);
	debug_dprintf(STDOUT_FILENO, "天井 color: 0x%06X\n", data->c_color);
	debug_dprintf(STDOUT_FILENO, "高さ height: %d\n", data->height);
	debug_dprintf(STDOUT_FILENO, "幅    width: %d\n", data->width);
	debug_dprintf(STDOUT_FILENO, "Player position: x = %f, y = %f, ", \
								data->player.x, data->player.y);
	debug_dprintf(STDOUT_FILENO, "dir = %f(%s)\n", \
				data->player.angle, get_player_angle_str(data->player.angle));
	debug_dprintf(STDOUT_FILENO, "以下、mapデータ: \n");
	if (!data->map)
		debug_dprintf(STDOUT_FILENO, "なし(null)\n");
	else
		print_map_data(data);
	debug_dprintf(STDOUT_FILENO, "---------------------------------\n\n");
	//mlxで描写して確認する。run_cub_map.sh使いたい場合はコメントアウトする
	// degub_mlx_data(data);
}

#else

void	debug_print_data(t_data *data)
{
	(void) data;
}
#endif
