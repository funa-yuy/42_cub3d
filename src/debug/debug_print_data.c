/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:31:41 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/11 14:35:36 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	degub_mlx_data(t_data *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	mlx_put_image_to_window(mlx, win, data->no_img, IMG_SIZE * 0, 0);
	mlx_put_image_to_window(mlx, win, data->so_img, IMG_SIZE * 1, 0);
	mlx_put_image_to_window(mlx, win, data->we_img, IMG_SIZE * 2, 0);
	mlx_put_image_to_window(mlx, win, data->ea_img, IMG_SIZE * 3, 0);
	mlx_loop(mlx);
}

void	debug_print_data(t_data *data)
{
	size_t	y;

	printf("----------- パース後 -------------\n");
	printf("MLX pointer: %p\n", data->mlx);
	printf("WIN pointer: %p\n", data->win);
	printf("北 texture: %p\n", data->no_img);
	printf("南 texture: %p\n", data->so_img);
	printf("西 texture: %p\n", data->we_img);
	printf("東 texture: %p\n", data->ea_img);
	printf("床   color: 0x%06X\n", data->f_color);
	printf("天井 color: 0x%06X\n", data->c_color);
	printf("Player position: x = %u, y = %u, dir = %c\n", \
	data->player.x, data->player.y, data->player.dir);
	y = -1;
	printf("以下、mapデータ: ");
	if (!data->map)
		printf("なし(null)\n");
	else
	{
		printf("\n");
		while (data->map && data->map[++y] != NULL)
			printf("%s\n", data->map[y]);
	}
	printf("---------------------------------\n\n");
	// degub_mlx_data(data);//mlxで描写して確認する。run_cub_map.sh使いたい場合はコメントアウトする
}
