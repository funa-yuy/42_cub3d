/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_cubdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:48:34 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/19 19:31:48 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_empty_line(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

t_strlst	*init_lst_data(char *file)
{
	int			fd;
	char		*line;
	t_strlst	*lines_list;
	t_strlst	*new;
	size_t		line_num;

	lines_list = NULL;
	line_num = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_perror_and_exit(file);
	line = get_next_line(fd);
	while (line != NULL)
	{
		//todo: 空行だったらリストに追加しない機能を追加する?map部分のから行はスキップしたくない
		if (line_num > 6 || !is_empty_line(line))
		{
			new = str_lstnew(line);
			if (!new)
				error_perror_and_exit(NULL);
			str_lstadd_back(&lines_list, new);
			line_num++;
		}
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
