/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:11:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/08 14:52:18 by miyuu            ###   ########.fr       */
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
		exit(ERR_SYSCALL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		new = str_lstnew(line);
		if (!new)
			exit(ERR_SYSCALL);
		str_lstadd_back(&lines_list, new);
		free(line);
		line = get_next_line(fd);
	}
	debug_print_strlst(lines_list);
	return (lines_list);
}

t_strlst	*normalize_cubfile(char *file)
{
	t_strlst	*lines_list;
	size_t		line_count;

	//gnlから読み取り
	lines_list = init_lst_data(file);
	line_count = str_lstsize(lines_list);
	(void)line_count;
	return (lines_list);
}

t_data	*init_cubdata(char *file)
{
	t_data		*data = NULL;
	t_strlst	*lines_list;

	// 正規化：strlst に格納
	lines_list = NULL;
	lines_list = normalize_cubfile(file);
	(void)lines_list;
/*
	// トーカナイズ：中間構造体への格納(parse_temp)に格納
	t_parse_tmp	*parsed;
	parsed = tokenize_lines(lines_list);
	//free_strlst(lines_list);

	// パース：構造体に格納
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(ERR_SYSCALL);
	//t_dataに格納
	data = parse_to_data();
	//free_parse_tmp(parsed);
*/
	return (data);
}
