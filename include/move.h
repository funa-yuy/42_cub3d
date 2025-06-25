/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:14:19 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/25 14:41:17 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

// ------------------------------------------------
// include header
// ------------------------------------------------

# include "cub3d.h"
# include <stdbool.h>
# include <math.h>

// ------------------------------------------------
// macro
// ------------------------------------------------

/* キーコード定義（macOS用） */
// # define KEY_ESC	53
// # define KEY_W	 13
// # define KEY_A	 0
// # define KEY_S	 1
// # define KEY_D	 2
// # define KEY_LEFT	123
// # define KEY_RIGHT	124
/* キーコード定義（Linux用） */
# define KEY_ESC	65307
# define KEY_W	 119
# define KEY_A	 97
# define KEY_S	 115
# define KEY_D	 100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

# define ROTATION_SPEED 0.8f
# define MOVE_SPEED 0.6f

// ------------------------------------------------
// function
// ------------------------------------------------
bool	can_move_position(t_data *data, float x, float y);

/* updata_angle.c */
void	update_angle_left(t_data *data);
void	update_angle_right(t_data *data);
void	rotate_player(t_data *data, float angle);

/* update_player_pos.c */
void	update_player_pos(t_data *data, float new_x, float new_y);
void	update_position_front(t_data *data);
void	update_position_left(t_data *data);
void	update_position_back(t_data *data);
void	update_position_right(t_data *data);

#endif
