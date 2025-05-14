/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:00:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/14 15:26:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(char *color)
{
	char	**rgb_tmp;
	int		r;
	int		g;
	int		b;
	int		result;

	//todo: 本来は、tokenizeでpathがcolorな場合のエラー処理するので、ここでは必要ない
	if (!color)
		error_print_and_exit("Invalid color value.");
	//todo: 一旦", "で区切られてる前提でやってる、もっと細かいparse関数を作る
	rgb_tmp = ft_split(color, ',');
	if (!rgb_tmp)
		error_perror_and_exit(NULL);
	r = ft_atoi(rgb_tmp[0]);
	g = ft_atoi(rgb_tmp[1]);
	b = ft_atoi(rgb_tmp[2]);
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	free(rgb_tmp[0]);
	free(rgb_tmp[1]);
	free(rgb_tmp[2]);
	free(rgb_tmp);
	return (result);
}

void	fill_color(t_data *data, const t_tokens_tmp *tokens)
{
	data->f_color = rgb_to_hex(tokens->f_rgb);
	data->c_color = rgb_to_hex(tokens->c_rgb);
}
