/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:10:37 by mfunakos          #+#    #+#             */
/*   Updated: 2025/06/21 21:11:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	rotate_player(t_data *data, float angle)
{
	data->player.angle += angle;
	while (data->player.angle >= 2.0f * M_PI)
		data->player.angle -= 2.0f * M_PI;
	while (data->player.angle < 0.0f)
		data->player.angle += 2.0f * M_PI;
}

void	update_angle_left(t_data *data)
{
	rotate_player(data, -ROTATION_SPEED);
}

void	update_angle_right(t_data *data)
{
	rotate_player(data, ROTATION_SPEED);
}
