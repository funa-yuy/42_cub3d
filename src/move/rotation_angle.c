/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:00:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/20 20:32:26 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

#define ANGLE_ROTATION_SPEED 5.0f  // 回転角度（度数法）

/**
 * 角度を度数法からラジアンに変換
 * @param degrees 度数法の角度
 * @return ラジアンの角度
 */
static float	degrees_to_radians(float degrees)
{
	return (degrees * M_PI / 180.0f);
}

/**
 * 角度をラジアンから度数法に変換
 * @param radians ラジアンの角度
 * @return 度数法の角度
 */
static float	radians_to_degrees(float radians)
{
	return (radians * 180.0f / M_PI);
}

/**
 * プレイヤーを指定した角度だけ回転させる（度数法版）
 * @param data プレイヤーデータ
 * @param angle_diff 回転角度（度数法、正の値で反時計回り）
 */
void	rotate_player_angle(t_data *data, float angle_diff)
{
	float	current_angle_deg;
	float	new_angle_deg;

	if (!data)
		return ;

	// 現在の角度を度数法に変換
	current_angle_deg = radians_to_degrees(data->player.angle);

	// 新しい角度を計算
	new_angle_deg = current_angle_deg + angle_diff;

	// 0-359度の範囲に正規化
	while (new_angle_deg >= 360.0f)
		new_angle_deg -= 360.0f;
	while (new_angle_deg < 0.0f)
		new_angle_deg += 360.0f;

	// ラジアンに変換して保存
	data->player.angle = degrees_to_radians(new_angle_deg);

	/* デバッグ出力 */
	debug_dprintf(STDOUT_FILENO, "Player rotated by %.1f deg (%.1f -> %.1f). New direction: (%.3f, %.3f)\n",
		angle_diff, current_angle_deg, new_angle_deg, cosf(data->player.angle), sinf(data->player.angle));
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

	// 角度をラジアンに変換して設定
	data->player.angle = degrees_to_radians(initial_angle);

	debug_dprintf(STDOUT_FILENO, "Player initial direction set to %.1f degrees. Direction vector: (%.3f, %.3f)\n",
		initial_angle, cosf(data->player.angle), sinf(data->player.angle));
}
