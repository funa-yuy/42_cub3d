
#include "cub3d.h"
#include "move.h"

/* キーコード定義（macOS用） */
// #define KEY_ESC	53

/* キーコード定義（Linux用） */
#define KEY_ESC	65307

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

// (x1,y1)と(x2,y2)の距離を計算
float	calc_distance(float x1, float y1, float x2, float y2)
{
	float	dx;
	float	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrtf(dx * dx + dy * dy));
}

void	debug_move_diff(t_data *data, float old_x, float old_y, float old_angle)
{
	float	distance;
	float	angle_diff;

	distance = calc_distance(old_x, old_y, data->player.x, data->player.y);
	angle_diff = calcu_angle_diff(old_angle, data->player.angle);

	printf("座標が (%.3f, %.3f) から (%.3f, %.3f) に移動. 移動距離: %.3f\n",
		old_x, old_y, data->player.x, data->player.y, distance);

	printf("angleが %.3f(%.2f°) から %.3f(%.2f°) に変更.差分: %.3f\n",
		old_angle, old_angle * 180.0f / M_PI,
		data->player.angle, data->player.angle * 180.0f / M_PI, \
		angle_diff);
}

int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	float	old_x;
	float	old_y;
	float	old_angle;

	old_x = data->player.x;
	old_y = data->player.y;
	old_angle = data->player.angle;
	if (keycode == KEY_ESC)
		close_window(data);
	else
		handle_key_input(keycode, data);
	debug_move_diff(data, old_x, old_y, old_angle);
	return (0);
}

/// ```bash
/// make test test/unit-tests/move/key_test00.c
/// ```

int	main(void)
{
	t_data	*target;

	target = init_cubdata("map/correct/simple.cub");
	printf("キー操作テスト開始\n");
	printf("操作: WASD(移動) 矢印キー(回転) ESC(終了)\n");
	printf("初期位置: (%.3f, %.3f), 初期角度: %.2f°, 移動速度: %.3f\n",
		target->player.x, target->player.y, \
		target->player.angle * 180.0f / M_PI, MOVE_SPEED);

	mlx_key_hook(target->win, handle_key, target);
	mlx_hook(target->win, 17, 0, close_window, target);
	mlx_loop(target->mlx);

	return (0);
}
