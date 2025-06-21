/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_visual_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:15:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 21:20:06 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "move.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400
#define MAP_SCALE 30
#define PLAYER_RADIUS 10
#define VIEW_LINE_LENGTH 50

typedef struct s_visual_test
{
	t_data		*game_data;
	void		*mlx;
	void		*window;
	void		*image;
	char		*img_data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_visual_test;

/**
 * ピクセルを描画
 */
void	put_pixel(t_visual_test *test, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = test->img_data + (y * test->line_length + x * (test->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

/**
 * 線を描画（Bresenhamアルゴリズム）
 */
void	draw_line(t_visual_test *test, int x0, int y0, int x1, int y1, int color)
{
	int	dx = abs(x1 - x0);
	int	dy = abs(y1 - y0);
	int	sx = (x0 < x1) ? 1 : -1;
	int	sy = (y0 < y1) ? 1 : -1;
	int	err = dx - dy;
	int	e2;

	while (1)
	{
		put_pixel(test, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

/**
 * 円を描画
 */
void	draw_circle(t_visual_test *test, int cx, int cy, int radius, int color)
{
	int	x, y;

	for (y = -radius; y <= radius; y++)
	{
		for (x = -radius; x <= radius; x++)
		{
			if (x * x + y * y <= radius * radius)
				put_pixel(test, cx + x, cy + y, color);
		}
	}
}

/**
 * プレイヤーと視点方向を描画
 */
void	draw_player(t_visual_test *test)
{
	int		px, py;
	int		view_end_x, view_end_y;
	float	view_x, view_y;

	// プレイヤー位置を画面座標に変換
	px = (int)(test->game_data->player.x * MAP_SCALE);
	py = (int)(test->game_data->player.y * MAP_SCALE);

	// 視点方向のベクトル計算
	view_x = cos(test->game_data->player.angle);
	view_y = sin(test->game_data->player.angle);

	// 視点方向線の終点計算
	view_end_x = px + (int)(view_x * VIEW_LINE_LENGTH);
	view_end_y = py + (int)(view_y * VIEW_LINE_LENGTH);

	// プレイヤーを青い円で描画
	draw_circle(test, px, py, PLAYER_RADIUS, 0x0088FF);

	// 視点方向を黄色い線で描画
	draw_line(test, px, py, view_end_x, view_end_y, 0xFFFF00);

	// 視点方向の先端に小さな点
	draw_circle(test, view_end_x, view_end_y, 3, 0xFF0000);
}

/**
 * 画面を描画
 */
void	render_scene(t_visual_test *test)
{
	// 画面をクリア（黒で塗りつぶし）
	for (int y = 0; y < WINDOW_HEIGHT; y++)
	{
		for (int x = 0; x < WINDOW_WIDTH; x++)
		{
			put_pixel(test, x, y, 0x000000);
		}
	}

	// 各要素を描画
	draw_player(test);

	// 画像をウィンドウに表示
	mlx_put_image_to_window(test->mlx, test->window, test->image, 0, 0);

	printf("angle: %.3f rad (%.1f°)\n",
		test->game_data->player.angle,
		test->game_data->player.angle * 180.0f / M_PI);
}

/**
 * キー入力処理
 */
int	handle_key(int keycode, t_visual_test *test)
{
	if (keycode == 53) // ESC
	{
		mlx_destroy_window(test->mlx, test->window);
		exit(0);
	}
	else if (keycode == KEY_LEFT)
	{
		handle_key_input(KEY_LEFT, test->game_data);
		render_scene(test);
	}
	else if (keycode == KEY_RIGHT)
	{
		handle_key_input(KEY_RIGHT, test->game_data);
		render_scene(test);
	}

	return (0);
}

/**
 * ウィンドウ閉じるボタンの処理
 */
int	close_window(t_visual_test *test)
{
	mlx_destroy_window(test->mlx, test->window);
	exit(0);
	return (0);
}

/**
 * 視覚的な視点移動テスト
 */
int	main(void)
{
	t_visual_test	test;

	test.game_data = init_cubdata("map/correct/simple.cub");
	test.mlx = mlx_init();
	test.window = mlx_new_window(test.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Rotation Test");
	test.image = mlx_new_image(test.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	test.img_data = mlx_get_data_addr(test.image, &test.bits_per_pixel,
		&test.line_length, &test.endian);

	render_scene(&test);

	mlx_hook(test.window, 2, 1L<<0, handle_key, &test);
	mlx_hook(test.window, 17, 1L<<17, close_window, &test);
	mlx_loop(test.mlx);

	return (0);
}

/// ```bash
/// make test test/unit-tests/move/rotation_visual_test.c
/// ```
