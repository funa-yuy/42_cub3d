/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:47:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 19:41:23 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

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
