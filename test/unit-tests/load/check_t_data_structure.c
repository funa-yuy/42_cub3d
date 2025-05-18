/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_t_data_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:13:19 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/18 18:16:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* t_data構造体の*/
/* 構造体の各フィールドに格納された値がすべて一致していればtrueそうでなければfalseを返却する関数*/
bool	check_t_data_structure(t_data *target, t_data *test)
{
	unsigned int	i;

	if (target->height != test->height)
		return (false);
	if (target->width != test->width)
		return (false);
	if (target->player.x != test->player.x)
		return (false);
	if (target->player.y != test->player.y)
		return (false);
	if (target->player.dir != test->player.dir)
		return (false);
	if (target->f_color != test->f_color)
		return (false);
	if (target->c_color != test->c_color)
		return (false);
	if (target->map != NULL && test->map != NULL)
	{
		i = 0;
		while (i < target->height * target->width)
		{
			if (target->map[i] != test->map[i])
				return (false);
			i++;
		}
	}
	else if (target->map != test->map)
		return (false);
	return (true);
}
