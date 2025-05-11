/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:45:38 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/11 13:18:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*parse_to_data(const t_tokens_tmp *tokens)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(ERR_SYSCALL);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(ERROR);
	data->win = mlx_new_window(data->mlx, 4 * IMG_SIZE, IMG_SIZE, "cub3D");
	fill_map(data, tokens->map_lines);//todo: ここでmapのバリデートする?
	// if (!data->map)todo: debugのために、一旦exitしない
	// 	exit(ERR_SYSCALL);
	fill_player_position(data);//todo: もし、プレイヤーがぞんざいしなかったらエラー(mapバリデートでやっちゃう？)
	fill_images(data, tokens);
	fill_color(data, tokens);
	return (data);
}
