/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:56:02 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/15 20:45:27 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_type	get_player_dir_enum(char str)
{
	if (str == '0' || str == 'N' || str == 'S' || str == 'E' || str == 'W')
		return (EMPTY);
	if (str == '1')
		return (WALL);
	if (str == ' ')
		return (NOTHING);
	//todo; error_print_and_exit("Invalid map value.");
	return (-1);
}

unsigned int	get_longest_width(const t_strlst *lines)
{
	unsigned int	max;
	unsigned int	now;

	max = 0;
	now = 0;
	while (lines)
	{
		now = ft_strlen(lines->str);
		if (now > max)
			max = now;
		lines = lines->next;
	}
	return (max);
}

void	fill_map_test(t_data *data, const t_strlst *lines)
{
	size_t		i;
	size_t		j;
	size_t		map_height;

	//もし、空行だったらexitする todo:正規化の段階で空だったらエラー吐くようにする
	data->height = str_lstsize(lines);
	data->width = get_longest_width(lines);
	data->map = (int *)ft_calloc(data->height * data->width + 1, sizeof(int));
	if (!data->map)
		error_perror_and_exit(NULL);
	i = 0;
	while (lines)
	{
		j = 0;
		while (j < data->width)
		{
			if (lines->str[j])
				data->map[i] = get_player_dir_enum(lines->str[j]);
			else
				data->map[i] = NOTHING;
			i++;
		}
		lines = lines->next;
	}
}

// cahr cが入って、対応するenumを返す関数を作る→もし、enumに入らない文字だったらどうするか考える。
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
	//todo: heightとwidthを格納する
	//todo: 幅×高さ分の領域をもつintの1次元配列に格納するようにする
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
