/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_tokens_tmp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:49 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 20:45:21 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_tokens_tmp(const t_tokens_tmp *p)
{
	size_t	y;

	printf("----------- トーカナイズ後 -------------\n");
	printf("北 path: %s\n", p->no_path);
	printf("南 path: %s\n", p->so_path);
	printf("西 path: %s\n", p->we_path);
	printf("東 path: %s\n", p->ea_path);
	printf("f_rgb: %s\n", p->f_rgb);
	printf("c_rgb: %s\n", p->c_rgb);
	y = -1;
	printf("以下、mapデータ: ");
	if (!p->map_lines)
		printf("なし(null)\n");
	else
	{
		printf("\n");
		while (p->map_lines && p->map_lines[++y] != NULL)
			printf("%s\n", p->map_lines[y]);
	}
	printf("---------------------------------\n\n");
}
