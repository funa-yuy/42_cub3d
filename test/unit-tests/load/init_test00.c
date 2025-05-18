/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:15:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/18 14:43:32 by miyuu            ###   ########.fr       */
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
void	init_test00(void)
{
	char	*input_string;	// <- 問題
	t_data	*target;		// <- 答え
	t_data	*data;			// <- 自作データ

	int	map[] = \
	{
		WALL, WALL, WALL, WALL, WALL, WALL, \
		WALL, EMPTY, EMPTY, WALL, EMPTY, WALL, \
		WALL, EMPTY, WALL, EMPTY, EMPTY, WALL, \
		WALL, WALL, EMPTY, EMPTY, EMPTY, WALL, \
		WALL, WALL, WALL, WALL, WALL, WALL \
	};
	target = &(t_data){\
		NULL, NULL, \
		5, 6, \
		NULL, map, (t_pos){4, 3, DIR_NORTH}, \
		NULL, NULL, NULL, NULL, 0xDC6400, 0xE11E00};

	input_string = "map/test_parse/ok/simple.cub";
	data = init_cubdata(input_string);
	data -> mlx = NULL;

	debug_print_data((t_data *)target);
	// 構造体の各フィールドに格納された値がすべて一致していればtrue、そうでなければfalseを返却する関数
	if (check_t_data_structure(target, data))
		printf("\x1b[32mOK!\x1b[32m\n");
	else
		printf("\x1b[31mERROR\x1b[31m\n");
}

int	main(void)
{
	init_test00();
	return (0);
}
