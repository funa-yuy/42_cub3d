/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:42:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/08 10:14:04 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	print_list(t_strlst *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s", lst->str);
// 		lst = lst->next;
// 	}
// }

// void	init_data(t_data **data, char *file)
// {
// 	t_strlst	*lines_list = NULL;
// 	t_strlst	*new;
// 	size_t		line_count;

// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		exit(ERR_SYSCALL);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		new = str_lstnew(line);
// 		if (!new)
// 			exit(ERR_SYSCALL);
// 		str_lstadd_back(lines_list, new);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	line_count = str_lstsize(lines_list);
// 	debug_print_data(line_list);
// }

void	fill_map_data(t_data **data, char *line, int y)
{
	(*data)->map[y] = ft_strdup(line);
}

/*
 * Function:init_data
 * ----------------------------
 * ss
 */
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
	debug_print_data(*data);
}
