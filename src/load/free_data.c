/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:30:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/07/07 20:54:03 by miyuu            ###   ########.fr       */
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
	mlx_destroy_image(d->mlx, d->mlx_img);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	free(d);
}
