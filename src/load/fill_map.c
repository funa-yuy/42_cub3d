/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:56:02 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/27 15:53:39 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_type	get_map_type_enum(char str)
{
	if (str == '0' || str == 'N' || str == 'S' || str == 'E' || str == 'W')
		return (EMPTY);
	if (str == '1')
		return (WALL);
	if (str == ' ')
		return (NOTHING);
	error_print_and_exit("Invalid map value.");
	return (-1);
}

void	set_data_map(t_data *data, char **map_lines)
{
	size_t		x;
	size_t		y;
	size_t		i;
	size_t		line_len;

	y = 0;
	i = 0;
	while (map_lines && map_lines[y])
	{
		x = 0;
		line_len = ft_strlen(map_lines[y]);
		if (line_len <= 0 || is_empty_line(map_lines[y]))
			error_print_and_exit("Invalid map value.");
		while (x < data->width)
		{
			if (x < line_len)
				data->map[i] = get_map_type_enum(map_lines[y][x]);
			else
				data->map[i] = NOTHING;
			x++;
			i++;
		}
		y++;
	}
}
/*
size_t	calc_index(unsigned int x, unsigned int y, unsigned int width)
{
	return (y * width + x);
}

//一番端にきている？
bool	is_at_boundary(int *map, size_t index, unsigned int width, unsigned int max)
{
	size_t	x;
	size_t	y;

	x = index % width;
	y = index / width;

	//上下左右端にいたらout x or y = 0, x = width - 1, y = height - 1
	if (x == 0 || x == width - 1 || y == 0 || y == (max / width) - 1)
		return (true);
	// if (index < width || (max - width <= index &&  index < max))
	// 	return (true);

	//2だったらout
	if (map[index] == NOTHING)
		return (true);

	//歩けない場所(範囲外、もしくはEMPTY以外)だったらfalse
	//右 右が範囲外もしくは
	if (index + 1 >= max || map[index + 1] == NOTHING)
		return (true);
	//左
	if (index - 1 < 0 || map[index - 1] == NOTHING)
		return (true);
	//下
	if (index + width >= max || map[index + width] == NOTHING)
		return (true);
	//上
	if (index - width < 0 || map[index - width] == NOTHING)
		return (true);

	// if (index + 1 >= max || index - 1 < 0 || index + width >= max || index - width < 0)
	// 	return (true);
	return (false);
}

bool	dfs(bool *visited, t_data *data, size_t index)
{
	unsigned int	max;
	int				*map;
	unsigned int	width;
	unsigned int	height;

	map = data->map;
	width = data->width;
	height = data->height;
	max = width * height;
	//一番端に来たかのチェック
	if (is_at_boundary(map, index, width, max))
		return (false);
	if (visited[index])
		return (true);
	//訪問済み
	visited[index] = true;
	//右
	if (index + 1 < max && map[index + 1] != WALL && \
		!visited[index + 1] && !dfs(visited, data, index + 1))
		return (false);
	//左
	if (index > 0 && map[index - 1] != WALL && \
		!visited[index - 1] && !dfs(visited, data, index - 1))
		return (false);
	//下
	if (index + width < max && map[index + width] != WALL && \
		!visited[index + width] && !dfs(visited, data, index + width))
		return (false);
	//上
	if (index >= width && map[index - width] != WALL && \
		!visited[index - width] && !dfs(visited, data, index - width))
		return (false);
	return (true);
}


bool	is_valid_map(t_data *data)
{
	bool	*visited;
	size_t	index;
	bool	result;

	//visited = mallocする width* height + 1;
	visited = (bool *)ft_calloc((data->width * data->height + 1), sizeof(bool));
	if (!visited)
		error_perror_and_exit(NULL);
	index = calc_index(data->player.x, data->player.y, data->width);
	result = dfs(visited, data, index);
	return (result);
}
*/

size_t	calc_index(size_t x, size_t y, unsigned int width)
{
	return (y * width + x);
}

bool	is_boundary_value(t_data *data, size_t x, size_t y)
{
	size_t			index;
	int				*map;
	unsigned int	width;
	unsigned int	height;

	map = data->map;
	width = data->width;
	height = data->height;
	/* 番端のlineにいたらout 左, 右, 上, 下 */
	if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
		return (true);

	/* 現在地が"NOTHING"だったらout */
	index = calc_index(x, y, width);
	if (map[index] == NOTHING)
		return (true);

	/* 左右上下に1マス進んだ先が"NOTHING"だったらout */
	//左に1マス
	if (map[index - 1] == NOTHING)
		return (true);
	//右に1マス
	if (map[index + 1] == NOTHING)
		return (true);
	//上に1マス
	if (map[index - width] == NOTHING)
		return (true);
	//下に1マス
	if (map[index + width] == NOTHING)
		return (true);

	return (false);
}

bool	is_surrounded_walls(t_data *data, size_t x, size_t y, bool *visited)
{
	size_t			index;
	unsigned int	width;
	unsigned int	height;
	int				*map;

	map = data->map;
	width = data->width;
	height = data->height;

	if (is_boundary_value(data, x, y))
		return (false);

	index = calc_index(x, y, width);
	if (visited[index])
		return (true);

	visited[index] = true;

	/*
	左右上下に1マス進んだ先を検証。
	→マス進むことができる(範囲内 & 壁ではない)かつ、訪れたことがない場合、dfsをする
	*/
	//左に1マス
	if (x > 0 && map[index - 1] != WALL && \
		!visited[index - 1] && !is_surrounded_walls(data, x - 1, y, visited))
		return (false);
	//右に1マス
	if (x + 1 < width && map[index + 1] != WALL && \
		!visited[index + 1] && !is_surrounded_walls(data, x + 1, y, visited))
		return (false);
	//上に1マス
	if (y > 0 && map[index - width] != WALL && \
		!visited[index - width] && !is_surrounded_walls(data, x, y - 1, visited))
		return (false);
	//下に1マス
	if (y + 1 < height && map[index + width] != WALL && \
		!visited[index + width] && !is_surrounded_walls(data, x, y + 1, visited))
		return (false);

	return (true);
}

bool	is_valid_map(t_data *data)
{
	bool	result;
	bool	*visited;

	visited = (bool *)ft_calloc((data->width * data->height + 1), sizeof(bool));
	if (!visited)
		error_perror_and_exit(NULL);
	result = is_surrounded_walls(data, data->player.x, data->player.y, visited);
	return (result);
}


void	fill_map(t_data *data, char **map_lines)
{
	data->map = (int *)ft_calloc(data->height * data->width + 1, sizeof(int));
	if (!data->map)
		error_perror_and_exit(NULL);
	set_data_map(data, map_lines);

	if (!is_valid_map(data))
		error_print_and_exit("The map is not surrounded by walls.");
}
