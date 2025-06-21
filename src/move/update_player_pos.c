/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/22 01:18:03 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	update_player_pos(t_data *data, float new_x, float new_y)
{
	if (can_move_position(data, new_x, new_y))
	{
		debug_dprintf(STDERR_FILENO, "Player collision detected at (%f, %f)\n", \
						new_x, new_y);
		return ;
	}
	data->player.x = new_x;
	data->player.y = new_y;
}

/* 前進: 方向ベクトルに基づいた移動 */
void	update_position_front(t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	float	new_x, new_y;
	float	dir_x, dir_y;

	dir_x = cosf(data->player.angle);
	dir_y = sinf(data->player.angle);

	move_x += dir_x * MOVE_SPEED;
	move_y += dir_y * MOVE_SPEED;

	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;

	update_player_pos(data, new_x, new_y);
}

/* 左移動: 方向ベクトルに垂直な方向への移動 */
void	update_position_left(t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	float	new_x, new_y;
	float	dir_x, dir_y;

	dir_x = cosf(data->player.angle);
	dir_y = sinf(data->player.angle);

	move_x += dir_y * MOVE_SPEED;
	move_y += -dir_x * MOVE_SPEED;

	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;

	update_player_pos(data, new_x, new_y);
}

/* 後退: 方向ベクトルの逆方向への移動 */
void	update_position_back(t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	float	new_x, new_y;
	float	dir_x, dir_y;

	dir_x = cosf(data->player.angle);
	dir_y = sinf(data->player.angle);

	move_x += -dir_x * MOVE_SPEED;
	move_y += -dir_y * MOVE_SPEED;

	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;

	update_player_pos(data, new_x, new_y);
}

/* 右移動: 方向ベクトルに垂直な方向への移動 */
void	update_position_right(t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	float	new_x, new_y;
	float	dir_x, dir_y;

	dir_x = cosf(data->player.angle);
	dir_y = sinf(data->player.angle);

	move_x += -dir_y * MOVE_SPEED;
	move_y += dir_x * MOVE_SPEED;

	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;

	update_player_pos(data, new_x, new_y);
}
