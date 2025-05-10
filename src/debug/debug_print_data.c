/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:31:41 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 17:05:44 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	debug_print_data(t_data *data)
// {
// 	int	y;
// 	int	x;

// 	printf("北 path: %s\n", data->texture->no_img);
// 	printf("南 path: %s\n", data->texture->so_img);
// 	printf("西 path: %s\n", data->texture->we_img);
// 	printf("東 path: %s\n", data->texture->ea_img);
// 	// printf("f_color: %d\n", data->texture->f_color);
// 	// printf("c_color: %d\n", data->texture->c_color);
// 	printf("f_color: %s\n", data->texture->f_color);
// 	printf("c_color: %s\n", data->texture->c_color);
// 	y = 0;
// 	x = 0;
// 	while (data->map[y] != NULL)
// 	{
// 		x = 0;
// 		while (data->map[y][x] != '\0' && data->map[y][x] != '\n')
// 		{
// 			if (y == data->player.y && x == data->player.x)
// 				printf("\x1b[31m%c\x1b[39m", data->map[y][x]);
// 			else
// 				printf("%c", data->map[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// }
