/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:15:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/15 18:54:27 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//todo: test書く
int	main(void)
{
	t_data	*data;
	int		size;

	size = IMG_SIZE;
	int	map[] = {
			WALL, WALL, WALL, WALL, WALL, WALL, \
			WALL, EMPTY, EMPTY, WALL, EMPTY, WALL, \
			WALL, EMPTY, WALL, EMPTY, EMPTY, WALL, \
			WALL, WALL, EMPTY, EMPTY, EMPTY, WALL, \
			WALL, WALL, WALL, WALL, WALL, WALL \
				};
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 4 * IMG_SIZE, IMG_SIZE, "cub3D");
	data->height = 5;
	data->width = 6;
	data->map_enum = map;
	data->player = (t_pos){4, 3, DIR_NORTH};
	data->no_img = mlx_xpm_file_to_image(data->mlx, "./textures/north.xpm", &size, &size);
	data->so_img = mlx_xpm_file_to_image(data->mlx, "./textures/south.xpm", &size, &size);
	data->we_img = mlx_xpm_file_to_image(data->mlx, "./textures/west.xpm", &size, &size);
	data->ea_img = mlx_xpm_file_to_image(data->mlx, "./textures/east.xpm", &size, &size);
	data->f_color = 0xDC6400;
	data->c_color = 0xE11E00;
	debug_print_data((t_data *)data);
	free_data((t_data *)data);
	return (0);
}
