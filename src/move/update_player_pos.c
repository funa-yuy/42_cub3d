/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/17 20:16:15 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	update_player_pos(t_data *data, float new_x, float new_y)
{
	/* 移動前に衝突判定を行う */
	if (can_move_position(data, new_x, new_y))
	{
		debug_dprintf(STDERR_FILENO, "Player collision detected at (%f, %f)\n", new_x, new_y);
		return ;
	}
	/* 衝突しない場合のみプレイヤー位置を更新 */
	data->player.x = new_x;
	data->player.y = new_y;
	debug_dprintf(STDOUT_FILENO, "Player moved to (%f, %f)\n", new_x, new_y);
}
