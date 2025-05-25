#include "cub3d.h"
#include "mlx_int.h"
#include <stdint.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

void	put_point(
	uint32_t *mlx_addr,
	int32_t	x,
	int32_t	y,
	uint32_t color)
{
	if (0 <= x && x < WINDOW_WIDTH && 0 <= y && y < WINDOW_HEIGHT)
	{
		mlx_addr[y * WINDOW_WIDTH + x] = color;
	}
}

uint32_t *get_image_addr(
	uint32_t *mlx_img
)
{
	int bpp;
	int size_line;
	int endian;
	uint32_t *mlx_addr;

	mlx_addr = \
		(uint32_t *)mlx_get_data_addr(
			mlx_img, 
			&bpp,
			&size_line,
			&endian);
	return (mlx_addr);
}

void make_it_blue(
	uint32_t *mlx_addr,
	int width,
	int height
)
{
	int i = 0;
	while(i < width * height)
	{
		mlx_addr[i] = 255 ^ mlx_addr[i];
		i += 1;
	}
}

/// ```bash
/// make test test/unit-tests/render/mlx_render_test01.c
/// ```
int main()
{
	void *mlx_ptr;
	void *mlx_win;
	uint32_t *mlx_img;
	uint32_t *mlx_addr;
	int bpp;
	int size_line;
	int endian;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 600, 600, "title");
	mlx_img = mlx_new_image(mlx_ptr, 600, 600);
	mlx_addr = (uint32_t *)mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);

	mlx_clear_window(mlx_ptr, mlx_win);
	int i = 0;
	while(i < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		mlx_addr[i] = 0x00ff00;
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);

	int width;
	int height;
	uint32_t *small_mlx_img;
	uint32_t *small_mlx_addr;

	small_mlx_img = mlx_xpm_file_to_image(mlx_ptr, "./textures/east.xpm", &width, &height);
	small_mlx_addr = get_image_addr(small_mlx_img);
	make_it_blue(small_mlx_addr, width, height);
	mlx_put_image_to_window(mlx_ptr, mlx_win, small_mlx_img, 0, 0);

	mlx_loop(mlx_ptr);
	return (0);
}
