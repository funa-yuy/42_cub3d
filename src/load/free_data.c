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
	mlx_destroy_image(d->mlx, d->no_img);
	mlx_destroy_image(d->mlx, d->so_img);
	mlx_destroy_image(d->mlx, d->we_img);
	mlx_destroy_image(d->mlx, d->ea_img);
	mlx_destroy_window(d->mlx, d->win);

	//mlx_destroy_display(d->no_img_addr);
	//mlx_destroy_display(d->so_img_addr);
	//mlx_destroy_display(d->we_img_addr);
	//mlx_destroy_display(d->ea_img_addr);
	//free(d->no_img_addr);
	//free(d->so_img_addr);
	//free(d->we_img_addr);
	//free(d->ea_img_addr);
	/* ---- macの場合、以下をコメントアウト ---- */
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	free(d);
}
