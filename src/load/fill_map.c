/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:56:02 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/25 14:59:15 by miyuu            ###   ########.fr       */
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

//todo: line_lenが空行(改行のみor空白のみ)だったらエラ-exitする
void	fill_map(t_data *data, char **map_lines)
{
	size_t		x;
	size_t		y;
	size_t		i;
	size_t		line_len;

	data->map = (int *)ft_calloc(data->height * data->width + 1, sizeof(int));
	if (!data->map)
		error_perror_and_exit(NULL);
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
