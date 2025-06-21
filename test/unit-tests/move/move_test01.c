#include "cub3d.h"
#include "move.h"
#include "render.h"
#include <math.h>
#include <stdlib.h>

/* ================================
 * マクロ定義
 * ================================ */
#define CELL_SIZE 20

/* ================================
 * 描画処理
 * ================================ */

void	draw_rectangle(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (x + i >= 0 && x + i < WINDOW_WIDTH &&
				y + j >= 0 && y + j < WINDOW_HEIGHT)
			{
				mlx_pixel_put(data->mlx, data->win, x + i, y + j, color);
			}
			j++;
		}
		i++;
	}
}

void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
	int	dx = abs(x1 - x0);
	int	dy = abs(y1 - y0);
	int	sx = (x0 < x1) ? 1 : -1;
	int	sy = (y0 < y1) ? 1 : -1;
	int	err = dx - dy;
	int	e2;

	while (1)
	{
		if (x0 >= 0 && x0 < WINDOW_WIDTH && y0 >= 0 && y0 < WINDOW_HEIGHT)
			mlx_pixel_put(data->mlx, data->win, x0, y0, color);

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

int	get_map_cell_color(t_data *data, unsigned int x, unsigned int y)
{
	size_t	index;

	index = calc_map_index(x, y, data->width);

	/* マップタイプに応じて色を設定 */
	if (data->map[index] == WALL)
		return (0xFF0000); /* 赤：壁 */
	else if (data->map[index] == EMPTY)
		return (0x00FF00); /* 緑：空きスペース */
	else
		return (0x000000); /* 黒：何もない */
}

void	draw_player_with_direction_line(t_data *data, int cell_size)
{
	int	player_pixel_x;
	int	player_pixel_y;
	int	player_size;
	int	line_end_x;
	int	line_end_y;
	int	line_length;
	float	dir_x, dir_y;

	/* プレイヤーの実際の位置をピクセル座標に変換 */
	player_pixel_x = (int)(data->player.x * cell_size);
	player_pixel_y = (int)(data->player.y * cell_size);

	/* プレイヤーサイズを大きく */
	player_size = cell_size; /* より大きなサイズ */
	line_length = cell_size * 2; /* より長い方向線 */

	/* プレイヤーを中央に配置するためオフセット調整 */
	int offset_x = player_pixel_x - player_size / 2;
	int offset_y = player_pixel_y - player_size / 2;

	/* プレイヤーを青色の四角で描画 */
	draw_rectangle(data, offset_x, offset_y, player_size, 0x0000FF);

	/* 角度から方向ベクトルを計算 */
	dir_x = cosf(data->player.angle);
	dir_y = sinf(data->player.angle);

	/* 方向を示す線を描画（より太く見えるように3本描画） */
	line_end_x = player_pixel_x + (int)(dir_x * line_length);
	line_end_y = player_pixel_y + (int)(dir_y * line_length);

	/* 中央の線 */
	draw_line(data, player_pixel_x, player_pixel_y, line_end_x, line_end_y, 0xFFFF00);
	/* 太く見えるように隣接する線も描画 */
	draw_line(data, player_pixel_x + 1, player_pixel_y, line_end_x + 1, line_end_y, 0xFFFF00);
	draw_line(data, player_pixel_x, player_pixel_y + 1, line_end_x, line_end_y + 1, 0xFFFF00);
}

void	draw_player_at_exact_position(t_data *data, int cell_size)
{
	/* 方向線付き四角形で描画 */
	draw_player_with_direction_line(data, cell_size);
}

void	render_map_grid(t_data *data)
{
	unsigned int	x, y;
	int				pixel_x, pixel_y;
	int				color;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			/* セル座標をピクセル座標に変換 */
			pixel_x = x * CELL_SIZE;
			pixel_y = y * CELL_SIZE;

			/* マップセルの色を取得 */
			color = get_map_cell_color(data, x, y);

			/* セルを描画 */
			draw_rectangle(data, pixel_x, pixel_y, CELL_SIZE, color);
			x++;
		}
		y++;
	}
}

//2D ------------------------------------------------------------
void	render_simple_map(t_data *data)
{
	/* 1. マップグリッドを描画 */
	render_map_grid(data);

	/* 2. プレイヤーを正確な位置に描画 */
	draw_player_at_exact_position(data, CELL_SIZE);
}

//3D ------------------------------------------------------------
void	render_3d_scene(t_data *data)
{

	ft_memset(data->mlx_addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(uint32_t));

	// レイキャスティングによる3D壁描画
	render_wall_to_screen(
		data,
		(t_axis_xy_frames) {
			.axis_x_frames = init_axis_x_frames(data),
			.axis_y_frames = init_axis_y_frames(data),
		},
		init_f32x4(0, data->player.x, data->player.y,
					data->player.angle)
	);

	// 描画されたイメージを画面に表示
	mlx_put_image_to_window(data->mlx, data->win, data->mlx_img, 0, 0);

	debug_dprintf(STDOUT_FILENO, "3D Scene rendered. Player at (%.2f, %.2f)\n",
		data->player.x, data->player.y);
}

void	draw_ui_text(t_data *data)
{
	char	pos_str[50];
	char	dir_str[50];
	float	dir_x, dir_y;

	dir_x = cosf(data->player.angle);
	dir_y = sinf(data->player.angle);

	snprintf(pos_str, sizeof(pos_str), "Player: (%.2f, %.2f)",
		data->player.x, data->player.y);
	snprintf(dir_str, sizeof(dir_str), "Direction: (%.3f, %.3f)",
		dir_x, dir_y);
	mlx_string_put(data->mlx, data->win, 10, 220, 0xFFFFFF, pos_str);
	mlx_string_put(data->mlx, data->win, 10, 240, 0xFFFFFF, dir_str);
	mlx_string_put(data->mlx, data->win, 10, 260, 0xFFFFFF,
		"WASD: Move, Arrow Keys: Rotate, ESC: Exit");
	mlx_string_put(data->mlx, data->win, 10, 280, 0xFFFFFF,
		"Player: Blue square with yellow direction line");
}

void	render_scene(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_ui_text(data);
	// render_simple_map(data);
	render_3d_scene(data);

	debug_dprintf(STDOUT_FILENO, "Scene rendered. Player at (%.2f, %.2f)\n",
		data->player.x, data->player.y);
}

/* ================================
 * キー操作
 * ================================ */

int	close_window(t_data *data)
{
	(void)data;
	//todo: testのため、freeは必要ない
	free_data(data);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	debug_dprintf(STDOUT_FILENO, "Key pressed: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(data);
	else
		handle_key_input(keycode, data);
	render_scene(data);
	return (0);
}

/* ================================
 * 初期化・セットアップ
 * ================================ */

void	setup_event_handlers(t_data *data)
{
	mlx_key_hook(data->win, key_press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}

void	start_game_loop(t_data *data)
{
	render_scene(data);
	setup_event_handlers(data);

	debug_dprintf(STDOUT_FILENO, "Starting main loop...\n");
	mlx_loop(data->mlx);
}

/// ```bash
/// make test test/unit-tests/move/move_test00.c
/// ```
int main()
{
	t_data	*target;			// <- 自作データ
	target = init_cubdata("map/correct/rhombus.cub");

	/* 回転行列版での初期方向設定（比較用） */
	init_player_direction_matrix(target, DIR_SOUTH);

	start_game_loop(target);

	return (0);
}
