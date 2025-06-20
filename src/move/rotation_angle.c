/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:00:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/20 17:45:49 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include <math.h>

#define ANGLE_ROTATION_SPEED 5.0f  // 回転角度（度数法）

/**
 * 方向ベクトルから角度を計算する（度数法）
 * @param dir_x X方向ベクトル成分
 * @param dir_y Y方向ベクトル成分
 * @return 角度（0-359度）
 */
static float	get_angle_from_direction(float dir_x, float dir_y)
{
	float	angle_rad;
	float	angle_deg;

	angle_rad = atan2f(dir_y, dir_x);
	angle_deg = angle_rad * 180.0f / M_PI;

	// 0-359度の範囲に正規化
	if (angle_deg < 0)
		angle_deg += 360.0f;

	return (angle_deg);
}

/**
 * 角度から方向ベクトルを計算する
 * @param angle 角度（度数法）
 * @param dir_x X方向ベクトル成分への参照
 * @param dir_y Y方向ベクトル成分への参照
 */
static void	set_direction_from_angle(float angle, float *dir_x, float *dir_y)
{
	float	angle_rad;

	angle_rad = angle * M_PI / 180.0f;
	*dir_x = cosf(angle_rad);
	*dir_y = sinf(angle_rad);
}

/**
 * プレイヤーを指定した角度だけ回転させる（度数法版）
 * @param data プレイヤーデータ
 * @param angle_diff 回転角度（度数法、正の値で反時計回り）
 */
void	rotate_player_angle(t_data *data, float angle_diff)
{
	float	current_angle;
	float	new_angle;

	if (!data)
		return ;

	// 現在の方向ベクトルから角度を取得
	current_angle = get_angle_from_direction(data->player.dir_x, data->player.dir_y);

	// 新しい角度を計算
	new_angle = current_angle + angle_diff;

	// 0-359度の範囲に正規化
	if (new_angle >= 360.0f)
		new_angle -= 360.0f;
	else if (new_angle < 0.0f)
		new_angle += 360.0f;

	// 新しい方向ベクトルを設定
	set_direction_from_angle(new_angle, &data->player.dir_x, &data->player.dir_y);

	/* デバッグ出力 */
	debug_dprintf(STDOUT_FILENO, "Player rotated by %.1f deg (%.1f -> %.1f). New direction: (%.3f, %.3f)\n",
		angle_diff, current_angle, new_angle, data->player.dir_x, data->player.dir_y);
}

/**
 * プレイヤーを左に回転させる（度数法版）
 * @param data プレイヤーデータ
 */
void	rotate_player_left_angle(t_data *data)
{
	rotate_player_angle(data, -ANGLE_ROTATION_SPEED); /* 負の角度で左回転 */
}

/**
 * プレイヤーを右に回転させる（度数法版）
 * @param data プレイヤーデータ
 */
void	rotate_player_right_angle(t_data *data)
{
	rotate_player_angle(data, ANGLE_ROTATION_SPEED); /* 正の角度で右回転 */
}




/**
 * プレイヤーの初期方向を設定する（度数法版）
 * @param data プレイヤーデータ
 * @param dir プレイヤーの初期方向
 */
void	init_player_direction_angle(t_data *data, t_player_dir dir)
{
	float	initial_angle;

	if (!data)
		return ;

	// 初期角度を設定（N=270度, E=0度, S=90度, W=180度）
	// ※画面座標系に合わせた角度設定
	switch (dir)
	{
		case DIR_NORTH:
			initial_angle = 270.0f;
			break;
		case DIR_EAST:
			initial_angle = 0.0f;
			break;
		case DIR_SOUTH:
			initial_angle = 90.0f;
			break;
		case DIR_WEST:
			initial_angle = 180.0f;
			break;
		default:
			initial_angle = 270.0f; // デフォルトは北向き
			break;
	}

	// 方向ベクトルを設定
	set_direction_from_angle(initial_angle, &data->player.dir_x, &data->player.dir_y);

	debug_dprintf(STDOUT_FILENO, "Player initial direction set to %.1f degrees. Direction vector: (%.3f, %.3f)\n",
		initial_angle, data->player.dir_x, data->player.dir_y);
}
