/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/17 20:15:51 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

bool	can_move_position(t_data *data, float x, float y)
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
	if (x < 0 || y < 0 || x >= width || y >= height)
		return (true);
	index = calc_map_index((size_t)x, (size_t)y, width);
	if (map[index] == WALL || map[index] == NOTHING)
		return (true);
	return (false);
}
