#include "cub3d.h"
#include "libft.h"
#include "render.h"
#include "vec.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

uint32_t *get_vertical_arr(void *img_arr, size_t index, size_t img_width, size_t img_height)
{
	uint32_t *arr;
	size_t i;

	arr = (uint32_t *)malloc(sizeof(uint32_t) * img_height);
	i = 0;
	while (i < img_height)
	{
		arr[i] = ((uint32_t *)img_arr)[img_width * i + index];
		i += 1;
	}
	return (arr);
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

/// ```bash
/// make test test/unit-tests/render/mlx_render_test03.c
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
	mlx_win = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "vertical drawing test");
	mlx_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_addr = (uint32_t *)mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);

	mlx_clear_window(mlx_ptr, mlx_win);
	int i = 0;
	while(i < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		mlx_addr[i] = 0x00ff00;
		i++;
	}

	int width;
	int height;
	uint32_t *small_mlx_img;
	uint32_t *small_mlx_addr;

	small_mlx_img = mlx_xpm_file_to_image(mlx_ptr, "./textures/east.xpm", &width, &height);
	small_mlx_addr = get_image_addr(small_mlx_img);

	i = 0;
	while (i < width)
	{
		uint32_t *arr;
		int height_size;

		height_size = 346;
		debug_dprintf(STDERR_FILENO, "width: %d height %d\n", width, height);
		arr = get_vertical_arr_n(
			small_mlx_addr, 
			i, 
			(t_vec_i32x4){0, height, width, 0},
			height_size
		);
		if (draw_vertical_line(
			mlx_addr, 
			(t_vec_i32x4){0, 100, 100 + i, 0},
			arr,
			height_size
		))
		{
			printf("ERROR!\n");
		}
		free(arr);
		i += 1;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

