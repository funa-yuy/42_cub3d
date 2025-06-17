/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/17 18:55:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall_pos(t_data *data, float x, float y)
{
	size_t			index;
	enum e_map_type	*map;
	unsigned int	width;
	unsigned int	height;

	if (!data || !data->map)
		return (true);
	map = data->map;
	width = data->width;
	height = data->height;

	/* マップの範囲外の場合は壁として扱う */
	if (x >= width || y >= height)
		return (true);

	/* 指定座標のマップタイプを取得 */
	index = calc_map_index(x, y, width);
	/* 壁またはNOTHINGの場合は衝突として扱う */
	if (map[index] == WALL || map[index] == NOTHING)
		return (true);
	return (false);
}

void	update_player_pos(t_data *data, float new_x, float new_y)
{
	/* 移動前に衝突判定を行う */
	if (is_wall_pos(data, new_x, new_y))
	{
		debug_dprintf(STDERR_FILENO, "Player collision detected at (%f, %f)\n", new_x, new_y);
		return ;
	}
	/* 衝突しない場合のみプレイヤー位置を更新 */
	data->player.x = new_x;
	data->player.y = new_y;
	debug_dprintf(STDOUT_FILENO, "Player moved to (%f, %f)\n", new_x, new_y);
}
