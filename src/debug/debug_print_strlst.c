/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_strlst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:36:50 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/14 20:46:19 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef DEBUG

void	debug_print_strlst(t_strlst *lst)
{
	debug_dprintf(STDOUT_FILENO, "------------ 正規化後 -------------\n");
	while (lst)
	{
		debug_dprintf(STDOUT_FILENO, "%s", lst->str);
		lst = lst->next;
	}
	debug_dprintf(STDOUT_FILENO, "---------------------------------\n\n");
}

#else

void	debug_print_strlst(t_strlst *lst)
{
	(void) lst;
}
#endif
