/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:00:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 21:00:31 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (!color)
		return (0);//todo: debugのために、一旦exitせずに終わる
	rgb = ft_split(color, ',');//todo: 一旦", "で区切られてる前提でやってる、もっと細かいparse関数を作る
	if (!rgb)
	{
		// exit(ERR_SYSCALL);
		return (0);//todo: debugのために、一旦exitせずに終わる
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	fill_color(t_data *data, const t_tokens_tmp *parsed)
{
	data->f_color = rgb_to_hex(parsed->f_rgb);
	data->c_color = rgb_to_hex(parsed->c_rgb);
}
