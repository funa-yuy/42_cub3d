/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:09 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/22 11:35:38 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	handle_key_input(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		update_position_front(data);
	else if (keycode == KEY_A)
		update_position_left(data);
	else if (keycode == KEY_S)
		update_position_back(data);
	else if (keycode == KEY_D)
		update_position_right(data);
	else if (keycode == KEY_LEFT)
		update_angle_left(data);
	else if (keycode == KEY_RIGHT)
		update_angle_right(data);
}
