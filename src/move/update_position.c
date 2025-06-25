/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:39:22 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/25 19:24:43 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	move_player_pos(t_data *data, float new_x, float new_y)
{
	if (can_move_position(data, new_x, new_y))
	{
		debug_dprintf(STDERR_FILENO, "Playerが壁にぶつかりました: (%f, %f)\n", \
						new_x, new_y);
		return ;
	}
	data->player.x = new_x;
	data->player.y = new_y;
}

void	update_position_front(t_data *data)
{
	float	move_x;
	float	move_y;
	float	new_x;
	float	new_y;

	move_x = 0;
	move_y = 0;
	move_x += cosf(data->player.angle) * MOVE_SPEED;
	move_y += sinf(data->player.angle) * MOVE_SPEED;
	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;
	move_player_pos(data, new_x, new_y);
}

void	update_position_left(t_data *data)
{
	float	move_x;
	float	move_y;
	float	new_x;
	float	new_y;

	move_x = 0;
	move_y = 0;
	move_x += sinf(data->player.angle) * MOVE_SPEED;
	move_y += -cosf(data->player.angle) * MOVE_SPEED;
	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;
	move_player_pos(data, new_x, new_y);
}

void	update_position_back(t_data *data)
{
	float	move_x;
	float	move_y;
	float	new_x;
	float	new_y;

	move_x = 0;
	move_y = 0;
	move_x += -cosf(data->player.angle) * MOVE_SPEED;
	move_y += -sinf(data->player.angle) * MOVE_SPEED;
	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;
	move_player_pos(data, new_x, new_y);
}

void	update_position_right(t_data *data)
{
	float	move_x;
	float	move_y;
	float	new_x;
	float	new_y;

	move_x = 0;
	move_y = 0;
	move_x += -sinf(data->player.angle) * MOVE_SPEED;
	move_y += cosf(data->player.angle) * MOVE_SPEED;
	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;
	move_player_pos(data, new_x, new_y);
}
