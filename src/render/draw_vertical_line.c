#include "cub3d.h"
#include "vec.h"
#include <stdint.h>
#include <unistd.h>

static void	put_point_only_check_y(uint32_t *mlx_addr, int32_t x, int32_t y,
		uint32_t color)
{
	if (0 <= y && y < WINDOW_HEIGHT)
		mlx_addr[y * WINDOW_WIDTH + x] = color;
}

int	draw_vertical_line(void *mlx_addr, t_vec_i32x4 start, uint32_t vline[],
		int vline_len)
{
	int	i;

	i = 0;
	if (!(0 <= start.x && start.x < WINDOW_WIDTH))
		return (1);
	while (i < vline_len)
	{
		put_point_only_check_y(mlx_addr, start.x, start.y + i, vline[i]);
		i += 1;
	}
	return (0);
}
