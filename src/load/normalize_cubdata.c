/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_cubdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:48:34 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/25 00:09:28 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_strlst	*init_lst_data(int fd)
{
	char		*line;
	t_strlst	*lines_list;
	t_strlst	*new;
	size_t		line_num;

	lines_list = NULL;
	line_num = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
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
	int			fd;

	//todo: fileの拡張子が.cubで終わるかをみる
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_perror_and_exit(file);
	lines_list = init_lst_data(fd);
	close(fd);
	debug_print_strlst(lines_list);
	return (lines_list);
}
