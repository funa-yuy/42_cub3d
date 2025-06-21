/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test22.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:15:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 15:05:56 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_t_data_structure(t_data *target, t_data *test);

/*
map/correct/map_05.cub

NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
000000000
011111110
010000010
010000E10
011111110
000000000
*/
int	init_test22(void)
{
	char	*input_string;	// <- 問題
	t_data	*target;		// <- 答え
	t_data	*data;			// <- 自作データ

	enum e_map_type	map[] = \
	{
		EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, \
		EMPTY, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY, \
		EMPTY, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, EMPTY, \
		EMPTY, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, EMPTY, \
		EMPTY, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY, \
		EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, \
	};
	target = &(t_data){\
		NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		NULL, NULL, 0xDC6400, 0xE11E00, /* f_color, c_color */\
		6, 9, /* height,width */\
		{.y = 3, .x = 6, .angle = M_PI / 2.0f}, map};/*player{y, x, dir}, map*/
	printf("\x1b[32m ================ ↓正解↓ ================ \x1b[39m\n");
	debug_print_data((t_data *)target);

	printf("\x1b[32m ================ ↓自作↓ ================= \x1b[39m\n");
	input_string = "map/correct/map_05.cub";
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

	status = init_test22();
	return (status);
}
