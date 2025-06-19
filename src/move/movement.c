/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:47:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/19 22:48:01 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

/* 前進: 方向ベクトルに基づいた移動 */
void	move_player_w(t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	float	new_x, new_y;

	move_x += data->player.dir_x * MOVE_SPEED;
	move_y += data->player.dir_y * MOVE_SPEED;

	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;

	update_player_pos(data, new_x, new_y);
}

/* 左移動: 方向ベクトルに垂直な方向への移動 */
void	move_player_a(t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	float	new_x, new_y;

	move_x += data->player.dir_y * MOVE_SPEED;
	move_y += -data->player.dir_x * MOVE_SPEED;

	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;

	update_player_pos(data, new_x, new_y);
}

/* 後退: 方向ベクトルの逆方向への移動 */
void	move_player_s(t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	float	new_x, new_y;

	move_x += -data->player.dir_x * MOVE_SPEED;
	move_y += -data->player.dir_y * MOVE_SPEED;

	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;

	update_player_pos(data, new_x, new_y);
}

/* 右移動: 方向ベクトルに垂直な方向への移動 */
void	move_player_d(t_data *data)
{
	float	move_x = 0;
	float	move_y = 0;
	float	new_x, new_y;

	move_x += -data->player.dir_y * MOVE_SPEED;
	move_y += data->player.dir_x * MOVE_SPEED;

	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;

	update_player_pos(data, new_x, new_y);
}

void	handle_key_input(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		move_player_w(data);
	else if (keycode == KEY_A)
		move_player_a(data);
	else if (keycode == KEY_S)
		move_player_s(data);
	else if (keycode == KEY_D)
		move_player_d(data);
	else if (keycode == KEY_LEFT)
		rotate_player_left(data);
	else if (keycode == KEY_RIGHT)
		rotate_player_right(data);
}
