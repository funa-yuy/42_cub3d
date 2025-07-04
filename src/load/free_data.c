/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:30:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/06/22 11:37:00 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(t_data *d)
{
	if (!d)
		return ;
	free(d->map);
	if (d->no_img)
		mlx_destroy_image(d->mlx, d->no_img);
	if (d->so_img)
		mlx_destroy_image(d->mlx, d->so_img);
	if (d->we_img)
		mlx_destroy_image(d->mlx, d->we_img);
	if (d->ea_img)
		mlx_destroy_image(d->mlx, d->ea_img);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		/* ---- macの場合、以下をコメントアウト ---- */
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	free(d);
}
