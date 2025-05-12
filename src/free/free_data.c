/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:30:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/12 22:04:38 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//todo : initディレクトリに入れる→initディレクトリのディレクトリ名も変える
void	free_data(t_data *d)
{
	if (!d)
		return ;
	free_str_array(d->map);
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
		// mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	free(d);
}
