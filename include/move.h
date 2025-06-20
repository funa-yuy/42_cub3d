/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:14:19 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/20 20:32:17 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

// ------------------------------------------------
// include header
// ------------------------------------------------

# include "cub3d.h"
# include <stdbool.h>
#include <math.h>

// ------------------------------------------------
// macro
// ------------------------------------------------

/* キーコード定義（macOS用） */
// # define KEY_ESC	53
// # define KEY_W	 13
// # define KEY_A	 0
// # define KEY_S	 1
// # define KEY_D	 2
// # define KEY_LEFT	123  // 左矢印キー
// # define KEY_RIGHT	124  // 右矢印キー
/* キーコード定義（Linux用） */
# define KEY_ESC	65307
# define KEY_W	 119
# define KEY_A	 97
# define KEY_S	 115
# define KEY_D	 100
# define KEY_LEFT	65361  // 左矢印キー
# define KEY_RIGHT	65363  // 右矢印キー

# define MOVE_SPEED 0.6f
# define ROTATION_SPEED 0.8f  // 回転角度（ラジアン）

// ------------------------------------------------
// function
// ------------------------------------------------

bool	can_move_position(t_data *data, float x, float y);

void	update_player_pos(t_data *data, float new_x, float new_y);
void	move_player_w(t_data *data);
void	move_player_a(t_data *data);
void	move_player_s(t_data *data);
void	move_player_d(t_data *data);
void	handle_key_input(int keycode, t_data *data);

/* 回転機能 */
void	rotate_player_left(t_data *data);
void	rotate_player_right(t_data *data);
void	rotate_player(t_data *data, float angle);
void	init_player_direction_matrix(t_data *data, t_player_dir dir);

/* 角度版回転機能 */
void	rotate_player_left_angle(t_data *data);
void	rotate_player_right_angle(t_data *data);
void	rotate_player_angle(t_data *data, float angle_diff);
void	init_player_direction_angle(t_data *data, t_player_dir dir);

#endif
