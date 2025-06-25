/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:39:22 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/25 19:46:23 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

/* 指定した角度(target_angle)に移動する */
void	move_player_pos(t_data *data, float target_angle)
{
	float	move_x;
	float	move_y;
	float	new_x;
	float	new_y;

	move_x = cosf(target_angle) * MOVE_SPEED;
	move_y = sinf(target_angle) * MOVE_SPEED;
	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;
	if (can_move_position(data, new_x, new_y))
	{
		debug_dprintf(STDERR_FILENO, "壁にぶつかりました: (%f, %f)\n", new_x, new_y);
		return ;
	}
	data->player.x = new_x;
	data->player.y = new_y;
}

/* 前: 0度方向に移動 */
void	update_position_front(t_data *data)
{
	move_player_pos(data, data->player.angle + 0);
}

/* 右: +90度方向に移動 */
void	update_position_left(t_data *data)
{
	move_player_pos(data, data->player.angle + M_PI_2);
}

/* 後: +180度方向に移動 */
void	update_position_back(t_data *data)
{
	move_player_pos(data, data->player.angle + M_PI);
}

/* 左: -90度方向に移動 */
void	update_position_right(t_data *data)
{
	move_player_pos(data, data->player.angle - M_PI_2);
}
