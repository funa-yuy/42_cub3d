/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_tokens_tmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:49 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 20:20:13 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_tokens_tmp(const t_tokens_tmp *p)
{
	size_t	y;
	size_t	x;

	printf("----------- トーカナイズ後 -------------\n");
	printf("北 path: %s\n", p->no_path);
	printf("南 path: %s\n", p->so_path);
	printf("西 path: %s\n", p->we_path);
	printf("東 path: %s\n", p->ea_path);
	printf("f_rgb: %s\n", p->f_rgb);
	printf("c_rgb: %s\n", p->c_rgb);
	y = 0;
	x = 0;
	printf("以下、mapデータ: %s\n", p->map_lines ? "あり↓" : "なし(null)");
	while (p->map_lines && p->map_lines[y] != NULL)
	{
		x = 0;
		while (p->map_lines[y][x] != '\0' && p->map_lines[y][x] != '\n')
		{
			printf("%c", p->map_lines[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("---------------------------------\n\n");
}
