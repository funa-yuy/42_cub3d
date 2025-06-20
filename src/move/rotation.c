/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:00:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/20 19:11:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include <math.h>

/**
 * プレイヤーを指定した角度だけ回転させる
 * @param data プレイヤーデータ
 * @param angle 回転角度（ラジアン、正の値で反時計回り）
 */
void	rotate_player(t_data *data, float angle)
{
	float	old_dir_x;
	float	old_dir_y;
	float	cos_angle;
	float	sin_angle;

	if (!data)
		return ;

	old_dir_x = data->player.dir_x;
	old_dir_y = data->player.dir_y;

	cos_angle = cosf(angle);
	sin_angle = sinf(angle);

	/* 回転行列を適用して新しい方向ベクトルを計算 */
	/* [cos -sin] [dir_x]   [new_dir_x] */
	/* [sin  cos] [dir_y] = [new_dir_y] */
	data->player.dir_x = old_dir_x * cos_angle - old_dir_y * sin_angle;
	data->player.dir_y = old_dir_x * sin_angle + old_dir_y * cos_angle;

	/* デバッグ出力 */
	debug_dprintf(STDOUT_FILENO, "Player rotated by %.3f rad. New direction: (%.3f, %.3f)\n",
		angle, data->player.dir_x, data->player.dir_y);
}

/**
 * プレイヤーを左に回転させる（画面上で左向きに回転）
 * @param data プレイヤーデータ
 */
void	rotate_player_left(t_data *data)
{
	rotate_player(data, -ROTATION_SPEED); /* 画面座標系では負の角度で左回転 */
}

/**
 * プレイヤーを右に回転させる（画面上で右向きに回転）
 * @param data プレイヤーデータ
 */
void	rotate_player_right(t_data *data)
{
	rotate_player(data, ROTATION_SPEED); /* 画面座標系では正の角度で右回転 */
}

/**
 * プレイヤーの初期方向を設定する（回転行列版）
 * @param data プレイヤーデータ
 * @param dir プレイヤーの初期方向
 */
void	init_player_direction_matrix(t_data *data, t_player_dir dir)
{
	if (!data)
		return ;

	// 各方向の方向ベクトルを直接設定
	switch (dir)
	{
		case DIR_NORTH:  // 北（上）
			data->player.dir_x = 0.0f;
			data->player.dir_y = -1.0f;
			break;
		case DIR_EAST:   // 東（右）
			data->player.dir_x = 1.0f;
			data->player.dir_y = 0.0f;
			break;
		case DIR_SOUTH:  // 南（下）
			data->player.dir_x = 0.0f;
			data->player.dir_y = 1.0f;
			break;
		case DIR_WEST:   // 西（左）
			data->player.dir_x = -1.0f;
			data->player.dir_y = 0.0f;
			break;
		default:
			data->player.dir_x = 0.0f;  // デフォルトは北向き
			data->player.dir_y = -1.0f;
			break;
	}

	debug_dprintf(STDOUT_FILENO, "Player initial direction set (matrix). Direction vector: (%.3f, %.3f)\n",
		data->player.dir_x, data->player.dir_y);
}
