/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:11:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/09 17:30:16 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*init_cubdata(char *file)
{
	t_data				*data;
	const t_strlst		*lines_list;
	const t_parse_tmp	*parsed;

	// 正規化：strlst に格納
	lines_list = NULL;
	lines_list = normalize_cubdata(file);

	// トーカナイズ：中間構造体への格納(parse_temp)に格納
	parsed = NULL;
	parsed = tokenize_lines(lines_list);
	// todo: ree_strlst(lines_list);
	(void)parsed;

	data = NULL;
/*
	// パース：構造体に格納
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(ERR_SYSCALL);
	//t_dataに格納
	data = parse_to_data();
	// todo: free_parse_tmp(parsed);
*/
	return (data);
}
