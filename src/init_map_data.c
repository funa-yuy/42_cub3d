/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:42:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/07 18:31:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_data(t_data *data)
{
	int	y;
	int	x;

	printf("北 path: %s\n", data->texture->no_img);
	printf("南 path: %s\n", data->texture->so_img);
	printf("西 path: %s\n", data->texture->we_img);
	printf("東 path: %s\n", data->texture->ea_img);
	printf("f_color: %d\n", data->texture->f_color);
	printf("c_color: %d\n", data->texture->c_color);
	y = 0;
	x = 0;
	while (data->map[y][x] != '\0')
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (y == data->player.y && x == data->player.x)
				printf("\x1b[31m%c\x1b[39m", data->map[y][x]);
			else
				printf("%c", data->map[y][x]);
			x++;
		}
		y++;
	}
}

void	init_data(t_data **data, char *file)
{
	int		fd;
	char	*line;
	(void) data;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
}
