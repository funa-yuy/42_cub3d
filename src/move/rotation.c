/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:00:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 19:23:13 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

/**
 * プレイヤーを指定した角度だけ回転させる
 * @param data プレイヤーデータ
 * @param angle 回転角度（ラジアン、正の値で反時計回り）
 */
void	rotate_player(t_data *data, float angle)
{
	if (!data)
		return ;

	data->player.angle += angle;

	/* 角度を 0 〜 2π の範囲に正規化 */
	while (data->player.angle >= 2.0f * M_PI)
		data->player.angle -= 2.0f * M_PI;
	while (data->player.angle < 0.0f)
		data->player.angle += 2.0f * M_PI;

	/* デバッグ出力 */
	debug_dprintf(STDOUT_FILENO, "Player rotated by %.3f rad. New angle: %.3f rad. Direction vector: (%.3f, %.3f)\n",
		angle, data->player.angle, cosf(data->player.angle), sinf(data->player.angle));
}

/**
 * プレイヤーを左に回転させる（画面上で左向きに回転）
 * @param data プレイヤーデータ
 */
void	update_angle_left(t_data *data)
{
	rotate_player(data, -ROTATION_SPEED); /* 画面座標系では負の角度で左回転 */
}

/**
 * プレイヤーを右に回転させる（画面上で右向きに回転）
 * @param data プレイヤーデータ
 */
void	update_angle_right(t_data *data)
{
	rotate_player(data, ROTATION_SPEED); /* 画面座標系では正の角度で右回転 */
}

/**
 * プレイヤーの初期方向を設定する（角度版）
 * @param data プレイヤーデータ
 * @param dir プレイヤーの初期方向
 */
void	init_player_direction_matrix(t_data *data, t_player_dir dir)
{
	if (!data)
		return ;

	if (dir == DIR_NORTH)
		data->player.angle = 3.0f * M_PI / 2.0f; // 270度
	else if (dir == DIR_EAST)
		data->player.angle = 0.0f; // 0度
	else if (dir == DIR_SOUTH)
		data->player.angle = M_PI / 2.0f; // 90度
	else if (dir == DIR_WEST)
		data->player.angle = M_PI; // 180度

	debug_dprintf(STDOUT_FILENO, "Player initial direction set (angle). Angle: %.3f rad. Direction vector: (%.3f, %.3f)\n",
		data->player.angle, cosf(data->player.angle), sinf(data->player.angle));
}
