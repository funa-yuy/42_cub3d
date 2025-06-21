/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:09 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 19:30:11 by miyuu            ###   ########.fr       */
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

// int	key_press(int keycode, t_data *data)
// {
// 	debug_dprintf(STDOUT_FILENO, "Key pressed: %d\n", keycode);
// 	if (keycode == KEY_ESC)
// 		close_window(data);
// 	else
// 		handle_key_input(keycode, data);
// 	render_scene(data);
// 	return (0);
// }
