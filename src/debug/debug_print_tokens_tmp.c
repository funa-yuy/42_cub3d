/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_tokens_tmp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:49 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/14 20:46:35 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef DEBUG

void	debug_print_tokens_tmp(const t_tokens_tmp *p)
{
	size_t	y;

	debug_dprintf(STDOUT_FILENO, "----------- トーカナイズ後 -------------\n");
	debug_dprintf(STDOUT_FILENO, "北 path: %s\n", p->no_path);
	debug_dprintf(STDOUT_FILENO, "南 path: %s\n", p->so_path);
	debug_dprintf(STDOUT_FILENO, "西 path: %s\n", p->we_path);
	debug_dprintf(STDOUT_FILENO, "東 path: %s\n", p->ea_path);
	debug_dprintf(STDOUT_FILENO, "f_rgb: %s\n", p->f_rgb);
	debug_dprintf(STDOUT_FILENO, "c_rgb: %s\n", p->c_rgb);
	y = -1;
	debug_dprintf(STDOUT_FILENO, "以下、mapデータ: ");
	if (!p->map_lines)
		debug_dprintf(STDOUT_FILENO, "なし(null)\n");
	else
	{
		debug_dprintf(STDOUT_FILENO, "\n");
		while (p->map_lines && p->map_lines[++y] != NULL)
			debug_dprintf(STDOUT_FILENO, "%s\n", p->map_lines[y]);
	}
	debug_dprintf(STDOUT_FILENO, "---------------------------------\n\n");
}

#else

void	debug_print_tokens_tmp(const t_tokens_tmp *p)
{
	(void) p;
}
#endif
