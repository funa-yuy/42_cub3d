/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:15:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/21 14:57:51 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_t_data_structure(t_data *target, t_data *test);

/*
NO ./textures/north.xpm

SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
111111
100101
101001
1100N1
111111
*/
int	init_test03(void)
{
	char	*input_string;	// <- 問題
	t_data	*target;		// <- 答え
	t_data	*data;			// <- 自作データ

	enum e_map_type	map[] = \
	{
		WALL, WALL, WALL, WALL, WALL, WALL, \
		WALL, EMPTY, EMPTY, WALL, EMPTY, WALL, \
		WALL, EMPTY, WALL, EMPTY, EMPTY, WALL, \
		WALL, WALL, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, WALL, WALL, WALL, WALL, WALL \
	};
	target = &(t_data){\
		NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		NULL, NULL, NULL, NULL, \
		NULL, NULL, 0xDC6400, 0xE11E00, /* f_color, c_color */\
		5, 6, /* height,width */\
		(t_pos){3, 4, .angle = 3.0f * M_PI / 2.0f}, .map = map};/*player, map*/
	printf("\x1b[32m ================ ↓正解↓ ================ \x1b[39m\n");
	debug_print_data((t_data *)target);

	printf("\x1b[32m ================ ↓自作↓ ================= \x1b[39m\n");
	input_string = "map/correct/2_or_more_nl_1.cub";
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

	status = init_test03();
	return (status);
}
