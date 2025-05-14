/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:56:02 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/14 15:27:57 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map(t_data *d, char **map_lines)
{
	size_t		y;
	size_t		map_height;

	//todo: mapのvalidateする
	if (!map_lines || !map_lines[0])
		error_print_and_exit("Invalid map value.");
	map_height = 0;
	while (map_lines[map_height])
		map_height++;
	d->map = (char **)ft_calloc(map_height + 1, sizeof(char *));
	if (!d->map)
		error_perror_and_exit(NULL);
	y = 0;
	while (map_lines[y])
	{
		d->map[y] = ft_strdup(map_lines[y]);
		if (!d->map[y])
			error_perror_and_exit(NULL);
		y++;
	}
}
