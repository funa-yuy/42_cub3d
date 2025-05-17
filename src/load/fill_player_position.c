/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:01:28 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/15 20:26:52 by miyuu            ###   ########.fr       */
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

void	fill_player_position(t_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (data->map && data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' \
				|| data->map[y][x] == 'S' \
				|| data->map[y][x] == 'E' \
				|| data->map[y][x] == 'W')
			{
				data->player = (t_pos){y, x, get_player_dir_enum(data->map[y][x])};
				//playerが正しく存在する前提なので。プレイヤー見つかったら終わる。ちゃんといるかをここで再度判定するのもあり
				return ;
			}
			x++;
		}
		y++;
	}
	error_print_and_exit("Player does not exist.");
}
