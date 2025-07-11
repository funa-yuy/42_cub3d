#include <cub3d.h>
#include <stdint.h>

static void	put_point_no_check(uint32_t *mlx_addr, int32_t index,
		uint32_t color)
{
	mlx_addr[index] = color;
}

int set_backcolor(void *mlx_addr, uint32_t ceil_color, uint32_t floor_color)
{
	size_t i;
	size_t max;

	i = 0;
	max = WINDOW_WIDTH * WINDOW_HEIGHT / 2;
	while (i < max)
	{
		put_point_no_check(mlx_addr, i, ceil_color);
		i += 1;
	}
	while(i - max < max)
	{
		put_point_no_check(mlx_addr, i, floor_color);
		i += 1;
	}
	return (0);
}
