/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:31:41 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/18 14:37:17 by miyuu            ###   ########.fr       */
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

char	get_map_type_c(t_map_type type)
{
	if (type == EMPTY)
		return ('0');
	if (type == WALL)
		return ('1');
	if (type == NOTHING)
		return (' ');
	return ('!');
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

void	debug_print_data(t_data *data)
{
	size_t	y;
	size_t	i;

	debug_dprintf(STDOUT_FILENO, "----------- パース後 -------------\n");
	debug_dprintf(STDOUT_FILENO, "MLX pointer: %p\n", data->mlx);
	debug_dprintf(STDOUT_FILENO, "WIN pointer: %p\n", data->win);
	debug_dprintf(STDOUT_FILENO, "北 texture: %p\n", data->no_img);
	debug_dprintf(STDOUT_FILENO, "南 texture: %p\n", data->so_img);
	debug_dprintf(STDOUT_FILENO, "西 texture: %p\n", data->we_img);
	debug_dprintf(STDOUT_FILENO, "東 texture: %p\n", data->ea_img);
	debug_dprintf(STDOUT_FILENO, "床   color: 0x%06X\n", data->f_color);
	debug_dprintf(STDOUT_FILENO, "天井 color: 0x%06X\n", data->c_color);
	debug_dprintf(STDOUT_FILENO, "Player position: x = %u, y = %u, dir = %s\n", \
	data->player.x, data->player.y, get_player_dir_str(data->player.dir));
	y = -1;
	//todo: char **mapの部分は消す
	debug_dprintf(STDOUT_FILENO, "以下、mapデータ: ");
	if (!data->map)
		debug_dprintf(STDOUT_FILENO, "なし(null)\n");
	else
	{
		debug_dprintf(STDOUT_FILENO, "\n");
		while (data->map && data->map[++y] != NULL)
			debug_dprintf(STDOUT_FILENO, "%s\n", data->map[y]);
	}
	i = 0;
	while (i < data->width * data->height)
	{
		printf("%c", get_map_type_c(data->map_enum[i]));
		if ((i + 1) % data->width == 0)
			printf("\n");
		i++;
	}
	debug_dprintf(STDOUT_FILENO, "---------------------------------\n\n");
	// degub_mlx_data(data);//mlxで描写して確認する。run_cub_map.sh使いたい場合はコメントアウトする
}

#else

void	debug_print_data(t_data *data)
{
	(void) data;
}
#endif
