/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_cubdata_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:57:02 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/13 20:27:46 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_strlst(t_strlst *list)
{
	t_strlst	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		free(list->str);
		free(list);
		list = tmp;
	}
}

int	main(void)
{
	const t_strlst		*lines_list;

	lines_list = NULL;
	lines_list = normalize_cubdata("map/test_parse/ok/simple.cub");
	debug_print_strlst((t_strlst *)lines_list);
	free_strlst((t_strlst *)lines_list);
	return (0);
}
