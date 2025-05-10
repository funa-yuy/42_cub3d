/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:11:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 21:59:27 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_strlst(t_strlst *list)
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

void	free_tokens_tmp(t_tokens_tmp *t)
{
	size_t	y;

	if (!t)
		return ;
	if (t->no_path)
		free(t->no_path);
	if (t->so_path)
		free(t->so_path);
	if (t->we_path)
		free(t->we_path);
	if (t->ea_path)
		free(t->ea_path);
	if (t->f_rgb)
		free(t->f_rgb);
	if (t->c_rgb)
		free(t->c_rgb);
	y = -1;
	if (t->map_lines)
	{
		while (t->map_lines[++y])
			free(t->map_lines[y]);
		free(t->map_lines);
	}
	free(t);
}

t_data	*init_cubdata(char *file)
{
	t_data				*data;
	const t_strlst		*lines_list;
	const t_tokens_tmp	*tokens;

	/* 正規化：strlst に格納 */
	lines_list = NULL;
	lines_list = normalize_cubdata(file);
	debug_print_strlst((t_strlst *)lines_list);
	/* トーカナイズ：中間構造体への格納(parse_temp)に格納 */
	tokens = NULL;
	tokens = tokenize_lines(lines_list);
	debug_print_tokens_tmp((t_tokens_tmp *)tokens);
	free_strlst((t_strlst *)lines_list);
	/* パース：構造体に格納 */
	data = parse_to_data(tokens);
	free_tokens_tmp((t_tokens_tmp *)tokens);
	return (data);
}
