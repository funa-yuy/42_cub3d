#include "cub3d.h"
#include "move.h"

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

void	draw_player_at_exact_position(t_data *data, int cell_size)
{
	int	player_pixel_x;
	int	player_pixel_y;
	int	player_size;

	/* プレイヤーの実際の位置をピクセル座標に変換 */
	player_pixel_x = (int)(data->player.x * cell_size);
	player_pixel_y = (int)(data->player.y * cell_size);

	/* プレイヤーサイズ（セルサイズの約半分） */
	player_size = cell_size / 2;

	/* プレイヤーを中央に配置するためオフセット調整 */
	player_pixel_x -= player_size / 2;
	player_pixel_y -= player_size / 2;

	/* プレイヤーを青色の四角で描画 */
	draw_rectangle(data, player_pixel_x, player_pixel_y, player_size, 0x0000FF);
}

void	render_map_grid(t_data *data)
{
	unsigned int	x, y;
	int				pixel_x, pixel_y;
	int				color;
	const int		cell_size = 15;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			/* セル座標をピクセル座標に変換 */
			pixel_x = x * cell_size;
			pixel_y = y * cell_size;

			/* マップセルの色を取得 */
			color = get_map_cell_color(data, x, y);

			/* セルを描画 */
			draw_rectangle(data, pixel_x, pixel_y, cell_size, color);
			x++;
		}
		y++;
	}
}

void	render_simple_map(t_data *data)
{
	const int	cell_size = 15;

	/* 1. マップグリッドを描画 */
	render_map_grid(data);

	/* 2. プレイヤーを正確な位置に描画 */
	draw_player_at_exact_position(data, cell_size);
}

void	draw_ui_text(t_data *data)
{
	char	pos_str[50];

	snprintf(pos_str, sizeof(pos_str), "Player: (%.2f, %.2f)",
		data->player.x, data->player.y);
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFFFFFF, pos_str);
	mlx_string_put(data->mlx, data->win, 10, 40, 0xFFFFFF,
		"WASD: Move, ESC: Exit");
}

void	render_scene(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_ui_text(data);
	render_simple_map(data);

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
	// free_data(data);
	exit(0);
	return (0);
}

int	handle_movement_keys(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		move_player_w(data);
	else if (keycode == KEY_A)
		move_player_a(data);
	else if (keycode == KEY_S)
		move_player_s(data);
	else if (keycode == KEY_D)
		move_player_d(data);
	else
		return (0); /* 移動キーではない */

	render_scene(data);
	return (1); /* 移動キーが押された */
}

int	key_press(int keycode, t_data *data)
{
	debug_dprintf(STDOUT_FILENO, "Key pressed: %d\n", keycode);

	if (keycode == KEY_ESC)
		close_window(data);
	else
		handle_movement_keys(keycode, data);
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
	t_data	*target;
	void	*mlx;
	void	*win;

	enum e_map_type	map[] = \
	{
		WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, \
		WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, EMPTY, EMPTY, WALL, WALL, WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, EMPTY, WALL, NOTHING, NOTHING, WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, EMPTY, WALL, NOTHING, NOTHING, WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, EMPTY, WALL, NOTHING, NOTHING, WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, EMPTY, EMPTY, WALL, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, \
	};

	/* MLXの初期化 */
	mlx = mlx_init();
	if (!mlx)
	{
		debug_dprintf(STDERR_FILENO, "Failed to initialize MLX\n");
		return (1);
	}
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D Player Test");
	if (!win)
	{
		debug_dprintf(STDERR_FILENO, "Failed to create window\n");
		return (1);
	}

	target = &(t_data){\
		mlx, win, \
		NULL, NULL, NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		NULL, NULL, 0xDC6400, 0xE11E00, /* f_color, c_color */\
		9, 11, /* height,width */\
		(t_pos){.y = 7.0, .x = 9.0, .dir_y = -1.0f, .dir_x = 0.0f, DIR_NORTH}, map};/*player, map*/

	start_game_loop(target);

	return (0);
}
