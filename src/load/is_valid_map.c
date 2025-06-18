/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:15:40 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/28 01:37:31 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_position(t_data *data, size_t x, size_t y)
{
	size_t			index;
	enum e_map_type				*map;
	unsigned int	width;
	unsigned int	height;

	map = data->map;
	width = data->width;
	height = data->height;
	/* マップの端にいたらout */
	if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
		return (false);
	/* 現在地が"NOTHING"だったらout */
	index = calc_map_index(x, y, width);
	if (map[index] == NOTHING)
		return (false);
	return (true);
}

bool	is_surrounded_walls(t_data *data, size_t x, size_t y, bool *visited)
{
	size_t			index;
	unsigned int	width;
	enum e_map_type				*map;

	map = data->map;
	width = data->width;
	if (!is_valid_position(data, x, y))
		return (false);
	index = calc_map_index(x, y, width);
	if (visited[index])
		return (true);
	visited[index] = true;
	if (map[index - 1] != WALL && !visited[index - 1] \
		&& !is_surrounded_walls(data, x - 1, y, visited))
		return (false);
	if (map[index + 1] != WALL && !visited[index + 1] \
		&& !is_surrounded_walls(data, x + 1, y, visited))
		return (false);
	if (map[index - width] != WALL && !visited[index - width] \
		&& !is_surrounded_walls(data, x, y - 1, visited))
		return (false);
	if (map[index + width] != WALL && !visited[index + width] \
		&& !is_surrounded_walls(data, x, y + 1, visited))
		return (false);
	return (true);
}

bool	is_valid_map(t_data *data)
{
	bool	*visited;
	bool	result;

	visited = (bool *)ft_calloc((data->width * data->height + 1), sizeof(bool));
	if (!visited)
		error_perror_and_exit(NULL);
	result = is_surrounded_walls(data, data->player.x, data->player.y, visited);
	free(visited);
	return (result);
}
