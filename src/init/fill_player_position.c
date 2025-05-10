/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:01:28 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 21:01:34 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				data->player = (t_pos){y, x, data->map[y][x]};
				//playerが正しく存在する前提なので。プレイヤー見つかったら終わる。ちゃんといるかをここで再度判定するのもあり
				return ;
			}
			x++;
		}
		y++;
	}
}
