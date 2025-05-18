/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_cubdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:48:34 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/18 18:33:43 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_strlst	*init_lst_data(char *file)
{
	int			fd;
	char		*line;
	t_strlst	*lines_list;
	t_strlst	*new;

	lines_list = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_perror_and_exit(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		//todo: 空行だったらリストに追加しない機能を追加する?map部分のから行はスキップしたくない
		new = str_lstnew(line);
		if (!new)
			error_perror_and_exit(NULL);
		str_lstadd_back(&lines_list, new);
		free(line);
		line = get_next_line(fd);
	}
	return (lines_list);
}

t_strlst	*normalize_cubdata(char *file)
{
	t_strlst	*lines_list;

	lines_list = init_lst_data(file);
	debug_print_strlst(lines_list);
	return (lines_list);
}
