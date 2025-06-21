/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_test00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:00:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 22:03:05 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "move.h"

// 差分を -π から π の範囲に正規化
float	calcu_angle_diff(float old_angle, float new_angle)
{
	float	diff;

	diff = new_angle - old_angle;
	while (diff > M_PI)
		diff -= 2.0f * M_PI;
	while (diff < -M_PI)
		diff += 2.0f * M_PI;
	return (diff);
}

void	process_key_input(t_data *data, int keycode)
{
	float	old_angle;

	old_angle = data->player.angle;
	if (keycode == KEY_LEFT)
	{
		printf("left: ");
		update_angle_left(data);
	}
	else if (keycode == KEY_RIGHT)
	{
		printf("right: ");
		update_angle_right(data);
	}
	printf("angleが %.3f(%.2f°) から %.3f(%.2f°) に変更.差分: %.3f\n",
		old_angle, old_angle * 180.0f / M_PI,
		data->player.angle, data->player.angle * 180.0f / M_PI, \
		calcu_angle_diff(old_angle, data->player.angle));
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		process_key_input(data, keycode);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit(0);
	return (0);
}

/// ```bash
/// make test test/unit-tests/move/rotation_test00.c
/// ```
// 回転する角度を変更したい場合は、move.hに定義されているROTATION_SPEEDの値を変更して下さい
int	main(void)
{
	t_data	*target;

	target = init_cubdata("map/correct/simple.cub");
	printf("視点移動テスト開始\n");
	printf("操作: 左右の矢印キーで回転、ESCで終了\n");
	printf("初期角度: %.3f rad (%.2f°), 回転角度: %.3f\n",
		target->player.angle, \
		target->player.angle * 180.0f / M_PI, \
		ROTATION_SPEED);
	mlx_key_hook(target->win, handle_key, target);
	mlx_hook(target->win, 17, 0, close_window, target);
	mlx_loop(target->mlx);
	return (0);
}
