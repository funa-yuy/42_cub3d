/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:11:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/25 17:32:56 by miyuu            ###   ########.fr       */
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
	free_str_array(t->map_lines);
	free(t);
}

bool	valid_cub_extension(char *filepath)
{
	size_t	len;
	char	*last_slash;
	char	*filename;

	if (!filepath)
		return (false);
	len = ft_strlen(filepath);
	if (len < 5)
		return (false);
	last_slash = ft_strrchr(filepath, '/');
	if (last_slash && filepath[len - 1] != '/')
		filename = last_slash + 1;
	else
		filename = filepath;
	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

t_data	*init_cubdata(char *file)
{
	t_data				*data;
	const t_strlst		*lines_list;
	const t_tokens_tmp	*tokens;

	if (!valid_cub_extension(file))
		error_print_and_exit("Invalid file extension.");
	/* 正規化：strlst に格納 */
	lines_list = NULL;
	lines_list = normalize_cubdata(file);
	/* トーカナイズ：中間構造体への格納(parse_temp)に格納 */
	tokens = NULL;
	tokens = tokenize_lines(lines_list);
	free_strlst((t_strlst *)lines_list);
	/* パース：構造体に格納 */
	data = parse_to_data(tokens);
	free_tokens_tmp((t_tokens_tmp *)tokens);
	debug_print_data(data);
	return (data);
}
