#include "cub3d.h"
#include "mlx_int.h"
#include <stdint.h>
#include <unistd.h>

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


uint32_t *get_image(void *mlx_ptr, char *filename)
{
	//int size;
	int width;
	int height;
	uint32_t *img;

	//size = 64;
	img = mlx_xpm_file_to_image(mlx_ptr, filename, &width, &height);
	debug_dprintf(STDERR_FILENO, "width(%d) height(%d)\n", width, height);
	return (img);
}

/// ```bash
/// make test test/unit-tests/render/mlx_render_test00.c
/// ```
int main()
{
	void *mlx_ptr;
	void *mlx_win;
	uint32_t *mlx_img;
	uint32_t *mlx_addr;
	uint32_t *mlx_small_img;
	int bpp;
	int size_line;
	int endian;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 600, 600, "title");
	mlx_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_addr = (uint32_t *)mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);

	mlx_clear_window(mlx_ptr, mlx_win);
	int i = 0;
	while(i < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		mlx_addr[i] = 0x00ff00;
		i++;
	}
	mlx_small_img = get_image(mlx_ptr, "./textures/east.xpm");
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_small_img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
