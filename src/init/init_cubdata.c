/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:11:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 21:20:48 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*init_cubdata(char *file)
{
	t_data				*data;
	const t_strlst		*lines_list;
	const t_tokens_tmp	*parsed;

	/* 正規化：strlst に格納 */
	lines_list = NULL;
	lines_list = normalize_cubdata(file);
	/* トーカナイズ：中間構造体への格納(parse_temp)に格納 */
	//todo parse_tempをtokens_tmpに命名変更する
	parsed = NULL;
	parsed = tokenize_lines(lines_list);
	// todo: free_strlst(lines_list);
	/* パース：構造体に格納 */
	data = parse_to_data(parsed);
	// todo: free_tokens_tmp(parsed);
	return (data);
}
