/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:42:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/07 19:25:52 by miyuu            ###   ########.fr       */
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
	// printf("f_color: %d\n", data->texture->f_color);
	// printf("c_color: %d\n", data->texture->c_color);
	printf("f_color: %s\n", data->texture->f_color);
	printf("c_color: %s\n", data->texture->c_color);
	y = 0;
	x = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0' && data->map[y][x] != '\n')
		{
			if (y == data->player.y && x == data->player.x)
				printf("\x1b[31m%c\x1b[39m", data->map[y][x]);
			else
				printf("%c", data->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	fill_map_data(t_data **data, char *line, int y)
{
	(*data)->map[y] = ft_strdup(line);
}

void	init_data(t_data **data, char *file)
{
	int		fd;
	char	*line;
	int		map_line;
	int		y;

	map_line = 0;
	t_texture	*texture;
	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		exit(ERR_SYSCALL);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			texture->no_img = ft_strdup(line);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			texture->so_img = ft_strdup(line);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			texture->we_img = ft_strdup(line);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			texture->ea_img = ft_strdup(line);
		else if (ft_strncmp(line, "F ", 2) == 0)
			texture->f_color = ft_strdup(line);
		else if (ft_strncmp(line, "C ", 2) == 0)
			texture->c_color = ft_strdup(line);
		else
			map_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);

	(*data)->map = (char **)malloc(sizeof(char *) * (map_line + 1));
	if (!(*data)->map)
		exit(ERR_SYSCALL);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line != NULL)
	{
		if (!(ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
			|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0))
		{
			fill_map_data(data, line, y++);
		}
		free(line);
		line = get_next_line(fd);
	}
	(*data)->map[map_line] = NULL;

	close(fd);
	(*data)->texture = texture;
	print_data(*data);
}
