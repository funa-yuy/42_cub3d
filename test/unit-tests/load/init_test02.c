/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:15:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/24 17:22:08 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_t_data_structure(t_data *target, t_data *test);

/*
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 90,8,10
C 0,244,11
  1111111
1100S001
1111111
*/
int	init_test02(void)
{
	char	*input_string;	// <- 問題
	t_data	*target;		// <- 答え
	t_data	*data;			// <- 自作データ

	enum e_map_type	map[] = \
	{
		NOTHING, NOTHING, WALL, WALL, WALL, WALL, WALL, WALL, WALL, \
		WALL, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, NOTHING,\
		WALL, WALL, WALL, WALL, WALL, WALL, WALL, NOTHING, NOTHING,\
	};
	target = &(t_data){\
		NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		0x5A080A, 0x00F40B, /* f_color, c_color */\
		3, 9, /* height,width */\
		(t_pos){1, 4, DIR_SOUTH}, map};/*player, map*/
	printf("\x1b[32m ================ ↓正解↓ ================ \x1b[39m\n");
	debug_print_data((t_data *)target);

	printf("\x1b[32m ================ ↓自作↓ ================= \x1b[39m\n");
	input_string = "map/correct/small.cub";
	data = init_cubdata(input_string);
	data -> mlx = NULL;

	if (check_t_data_structure(target, data))
	{
		printf("\x1b[32mOK!\x1b[39m\n");
		return (0);
	}
	else
	{
		printf("\x1b[31mERROR\x1b[39m\n");
		return (1);
	}
}

int	main(void)
{
	int	status;

	status = init_test02();
	return (status);
}
