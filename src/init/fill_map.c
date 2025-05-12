/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:56:02 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/12 22:08:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// cahr cが入って、対応するenumを返す関数を作る→もし、enumに入らない文字だったらどうするか考える。
void	fill_map(t_data *d, char **map_lines)
{
	size_t		y;
	size_t		map_height;

	//もし、空行だったらexitする todo:正規化の段階でからだったらエラー吐くようにする?
	if (!map_lines || !map_lines[0])
	{
		//todo : free
		// exit(ERROR);//todo: debugのために、一旦exitせずに終わる
		return ;
	}
	map_height = 0;
	while (map_lines[map_height])
		map_height++;
	//todo: heightとwidthを格納する
	//todo: 幅×高さ分の領域をもつintの1次元配列に格納するようにする
	d->map = (char **)ft_calloc(map_height + 1, sizeof(char *));
	if (!d->map)
		exit(ERR_SYSCALL);
	y = 0;
	while (map_lines[y])
	{
		d->map[y] = ft_strdup(map_lines[y]);
		y++;
	}
}
