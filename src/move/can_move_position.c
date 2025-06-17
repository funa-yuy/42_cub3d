/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/17 21:43:47 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

/*
 * 引数で与えられた座標(x, y) に移動できるかを判定する関数
 *
 * マップの範囲外 or WALL or NOTHINGの場合は true（移動不可）を返す。
 * 移動可能なマスであれば false を返す。
 */
bool	can_move_position(t_data *data, float x, float y)
{
	size_t				index;
	unsigned int		width;
	unsigned int		height;
	enum e_map_type		*map;

	width = data->width;
	height = data->height;
	if (x < 0.0f || y < 0.0f || x >= width || y >= height)
		return (true);
	index = calc_map_index((size_t)x, (size_t)y, width);
	map = data->map;
	if (data->map[index] == WALL || data->map[index] == NOTHING)
		return (true);
	return (false);
}
