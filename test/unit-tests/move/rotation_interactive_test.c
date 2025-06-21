/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_interactive_test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:00:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 21:29:57 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "move.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
	printf("angleが %.3f(%.2f°) から %.3f(%.2f°) に変更\n",
		old_angle, old_angle * 180.0f / M_PI,
		data->player.angle, data->player.angle * 180.0f / M_PI);
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
	exit(0);
	return (0);
}

/// ```bash
/// make test test/unit-tests/move/rotation_interactive_test.c
/// ```
int	main(void)
{
	t_data	*target;

	target = init_cubdata("map/correct/simple.cub");

	printf("視点移動テスト開始\n");
	printf("操作: 左右の矢印キーで回転、ESCで終了\n");
	printf("初期角度: %.3f rad (%.2f°)\n",
		target->player.angle,
		target->player.angle * 180.0f / M_PI);

	mlx_key_hook(target->win, handle_key, &target);
	mlx_hook(target->win, 17, 0, close_window, &target);
	mlx_loop(target->mlx);

	free_data(target);
	return (0);
}
