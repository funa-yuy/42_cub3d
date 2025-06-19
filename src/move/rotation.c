/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:00:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/19 23:02:08 by miyuu            ###   ########.fr       */
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
