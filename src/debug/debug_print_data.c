/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:31:41 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/18 15:48:22 by miyuu            ###   ########.fr       */
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

char	*get_player_dir_str(t_player_dir dir)
{
	if (DIR_NORTH == dir)
		return ("DIR_NORTH");
	if (DIR_SOUTH == dir)
		return ("DIR_SOUTH");
	if (DIR_EAST == dir)
		return ("DIR_EAST");
	if (DIR_WEST == dir)
		return ("DIR_WEST");
	return (NULL);
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
	debug_dprintf(STDOUT_FILENO, "北 texture: %p\n", data->no_img);
	debug_dprintf(STDOUT_FILENO, "南 texture: %p\n", data->so_img);
	debug_dprintf(STDOUT_FILENO, "西 texture: %p\n", data->we_img);
	debug_dprintf(STDOUT_FILENO, "東 texture: %p\n", data->ea_img);
	debug_dprintf(STDOUT_FILENO, "北 addr: %p\n", data->no_img_addr);
	debug_dprintf(STDOUT_FILENO, "南 addr: %p\n", data->so_img_addr);
	debug_dprintf(STDOUT_FILENO, "西 addr: %p\n", data->we_img_addr);
	debug_dprintf(STDOUT_FILENO, "東 addr: %p\n", data->ea_img_addr);
	debug_dprintf(STDOUT_FILENO, "床   color: 0x%06X\n", data->f_color);
	debug_dprintf(STDOUT_FILENO, "天井 color: 0x%06X\n", data->c_color);
	debug_dprintf(STDOUT_FILENO, "高さ height: %d\n", data->height);
	debug_dprintf(STDOUT_FILENO, "幅    width: %d\n", data->width);
	debug_dprintf(STDOUT_FILENO, "Player position: x = %u, y = %u, dir = %s\n", \
	data->player.x, data->player.y, get_player_dir_str(data->player.dir));
	debug_dprintf(STDOUT_FILENO, "以下、mapデータ: \n");
	if (!data->map)
		debug_dprintf(STDOUT_FILENO, "なし(null)\n");
	else
		print_map_data(data);
	debug_dprintf(STDOUT_FILENO, "---------------------------------\n\n");
	// degub_mlx_data(data);//mlxで描写して確認する。run_cub_map.sh使いたい場合はコメントアウトする
}

#else

void	debug_print_data(t_data *data)
{
	(void) data;
}
#endif
