/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:45:38 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/18 15:47:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_map_height(char **map)
{
	unsigned int	height;

	if (!map)
		return (0);
	height = 0;
	while (map[height])
		height++;
	return (height);
}

unsigned int	get_longest_width(char **map)
{
	unsigned int	max;
	unsigned int	now;
	size_t			i;

	if (!map)
		return (0);
	max = 0;
	now = 0;
	i = 0;
	while (map[i])
	{
		now = ft_strlen(map[i]);
		if (now > max)
			max = now;
		i++;
	}
	return (max);
}

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
	//todo: もし、プレイヤーがぞんざいしなかったらエラー(mapバリデートでやっちゃう？)
	fill_player_position(data, tokens->map_lines);
	data->height = get_map_height(tokens->map_lines);
	data->width = get_longest_width(tokens->map_lines);
	fill_map(data, tokens->map_lines);//todo: ここでmapのバリデートする?
	return (data);
}
