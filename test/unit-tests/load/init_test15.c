/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test15.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:30:00 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/25 19:37:35 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_t_data_structure(t_data *target, t_data *test);

/*
map/correct/rhombus.cub

NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
   1
  101
 10001
100S001
 10001
  101
   1
*/
int	init_test15(void)
{
	char	*input_string;	// <- 問題
	t_data	*target;		// <- 答え
	t_data	*data;			// <- 自作データ

	int	map[] = \
	{
		NOTHING, NOTHING, NOTHING, WALL, NOTHING, NOTHING, NOTHING, \
		NOTHING, NOTHING, WALL, EMPTY, WALL, NOTHING, NOTHING, \
		NOTHING, WALL, EMPTY, EMPTY, EMPTY, WALL, NOTHING, \
		WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, \
		NOTHING, WALL, EMPTY, EMPTY, EMPTY, WALL, NOTHING, \
		NOTHING, NOTHING, WALL, EMPTY, WALL, NOTHING, NOTHING, \
		NOTHING, NOTHING, NOTHING, WALL, NOTHING, NOTHING, NOTHING \
	};
	target = &(t_data){\
		NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		0xDC6400, 0xE11E00, /* f_color, c_color */\
		7, 7, /* height,width */\
		(t_pos){3, 3, DIR_SOUTH}, map};/*player, map*/
	printf("\x1b[32m ================ ↓正解↓ ================ \x1b[39m\n");
	debug_print_data((t_data *)target);

	printf("\x1b[32m ================ ↓自作↓ ================= \x1b[39m\n");
	input_string = "map/correct/rhombus.cub";
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

	status = init_test15();
	return (status);
}
