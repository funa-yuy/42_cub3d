/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:11:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/08 16:54:29 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parse_tmp	*tokenize_lines(t_strlst *lines)
{
	(void)lines;
	return (NULL);
}

t_data	*init_cubdata(char *file)
{
	t_data		*data = NULL;
	t_strlst	*lines_list;
	t_parse_tmp	*parsed;

	// 正規化：strlst に格納
	lines_list = NULL;
	lines_list = normalize_cubdata(file);

	// トーカナイズ：中間構造体への格納(parse_temp)に格納
	parsed = NULL;
	parsed = tokenize_lines(lines_list);
	// free_strlst(lines_list);
	(void)parsed;

/*
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
