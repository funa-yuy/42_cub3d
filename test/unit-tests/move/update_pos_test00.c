
#include "cub3d.h"
#include "move.h"

// (x1,y1)と(x2,y2)の距離を計算
float	calc_distance(float x1, float y1, float x2, float y2)
{
	float	dx;
	float	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrtf(dx * dx + dy * dy));
}

void	process_movement_input(t_data *data, int keycode)
{
	float	old_x, old_y;
	float	distance;

	old_x = data->player.x;
	old_y = data->player.y;
	if (keycode == KEY_W)
	{
		printf("前: ");
		update_position_front(data);//ここで移動関数を呼び出す
	}
	else if (keycode == KEY_S)
	{
		printf("後: ");
		update_position_back(data);//ここで移動関数を呼び出す
	}
	else if (keycode == KEY_A)
	{
		printf("左: ");
		update_position_left(data);//ここで移動関数を呼び出す
	}
	else if (keycode == KEY_D)
	{
		printf("右: ");
		update_position_right(data);//ここで移動関数を呼び出す
	}
	distance = calc_distance(old_x, old_y, data->player.x, data->player.y);
	printf("座標が (%.3f, %.3f) から (%.3f, %.3f) に移動. 移動距離: %.3f\n",
		old_x, old_y, data->player.x, data->player.y, distance);
}

int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W || keycode == KEY_S || \
			 keycode == KEY_A || keycode == KEY_D)
		process_movement_input(data, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		float old_angle = data->player.angle;
		if (keycode == KEY_LEFT)
		{
			printf("左回転: ");
			update_angle_left(data);
		}
		else
		{
			printf("右回転: ");
			update_angle_right(data);
		}
		printf("角度が %.3f° から %.3f° に変更\n",
			old_angle * 180.0f / M_PI,
			data->player.angle * 180.0f / M_PI);
	}
	return (0);
}

/// ```bash
/// make test test/unit-tests/move/update_pos_test00.c
/// ```
// 移動速度を変更したい場合は、move.hに定義されているMOVE_SPEEDの値を変更してください
int	main(void)
{
	t_data	*target;

	target = init_cubdata("map/correct/simple.cub");
	printf("位置移動テスト開始\n");
	printf("操作: WASD(移動) 矢印キー(回転) ESC(終了)\n");
	printf("初期位置: (%.3f, %.3f), 初期角度: %.2f°, 移動速度: %.3f\n",
		target->player.x, target->player.y, \
		target->player.angle * 180.0f / M_PI, MOVE_SPEED);

	mlx_key_hook(target->win, handle_key, target);
	mlx_hook(target->win, 17, 0, close_window, target);
	mlx_loop(target->mlx);

	return (0);
}
