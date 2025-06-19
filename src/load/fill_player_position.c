/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:01:28 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/19 22:39:00 by miyuu            ###   ########.fr       */
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

bool	is_player_dir_char(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'W')
		return (true);
	return (false);
}

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
			if (is_player_dir_char(map_lines[y][x]))
			{
				if (player_found)
					error_print_and_exit("There are multiple players.");
				data->player = \
						(t_pos){.y = y, .x = x, get_player_dir_enum(map_lines[y][x])};
				player_found = true;
			}
			x++;
		}
		y++;
	}
	if (!player_found)
		error_print_and_exit("Player does not exist.");
}
