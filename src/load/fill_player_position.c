/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:01:28 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/22 11:36:45 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

float	get_player_angle(char c)
{
	if (c == 'N')
		return (3.0f * M_PI / 2.0f);
	else if (c == 'S')
		return (0.0f);
	else if (c == 'E')
		return (M_PI / 2.0f);
	else if (c == 'W')
		return (M_PI);
	return (0.0f);
}

void	fill_player_position(t_data *data, char **map_lines)
{
	size_t			y;
	size_t			x;
	bool			player_found;

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
				data->player = (t_pos){.y = y, .x = x, \
								.angle = get_player_angle(map_lines[y][x])};
				player_found = true;
			}
			x++;
		}
		y++;
	}
	if (!player_found)
		error_print_and_exit("Player does not exist.");
}
