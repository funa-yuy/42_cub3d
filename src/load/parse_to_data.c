/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:45:38 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/14 15:28:18 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*parse_to_data(const t_tokens_tmp *tokens)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		error_perror_and_exit(NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		error_print_and_exit("mlx_init failed");
	data->win = mlx_new_window(data->mlx, 4 * IMG_SIZE, IMG_SIZE, "cub3D");
	fill_images(data, tokens);
	fill_color(data, tokens);
	fill_map(data, tokens->map_lines);//todo: ここでmapのバリデートする?
	fill_player_position(data);//todo: もし、プレイヤーがぞんざいしなかったらエラー(mapバリデートでやっちゃう？)
	return (data);
}
