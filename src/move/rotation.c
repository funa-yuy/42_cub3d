/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:00:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 19:52:30 by mfunakos         ###   ########.fr       */
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
