/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:01:28 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/18 15:42:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player_dir	get_player_dir_enum(char dir)
{
	if ('N' == dir)
		return (DIR_NORTH);
	if ('S' == dir)
		return (DIR_SOUTH);
	if ('E' == dir)
		return (DIR_EAST);
	if ('W' == dir)
		return (DIR_WEST);
	return (-1);
}

//todo: リファクタリングしたい。ネストが深くなってる
void	fill_player_position(t_data *data, char **map_lines)
{
	size_t	y;
	size_t	x;
	bool	player_found;

	y = 0;
	player_found = false;
	while (map_lines && map_lines[y])
	{
		x = 0;
		while (map_lines[y][x])
		{
			if (map_lines[y][x] == 'N' || map_lines[y][x] == 'S' \
				|| map_lines[y][x] == 'E' || map_lines[y][x] == 'W')
			{
				if (!player_found)
				{
					data->player = (t_pos){y, x, get_player_dir_enum(map_lines[y][x])};
					player_found = true;
				}
				else
					error_print_and_exit("There are multiple players.");
			}
			x++;
		}
		y++;
	}
	if (!player_found)
		error_print_and_exit("Player does not exist.");
}
