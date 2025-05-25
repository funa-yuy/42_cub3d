/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:00:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/25 16:55:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_integer(char *str)
{
	size_t	i;

	if (!str || !str[i])
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	convert_rgb_integer(char *str)
{
	int	value;

	if (!is_integer(str))
		error_print_and_exit("Invalid color value.");
	value = ft_atoi(str);
	if (value < 0 || value > 255)
		error_print_and_exit("Color value must be between 0-255.");
	return (value);
}

int	rgb_to_hex(char *color)
{
	char	**rgb_tmp;
	int		r;
	int		g;
	int		b;
	int		result;

	if (!color)
		error_print_and_exit("Invalid color value.");
	rgb_tmp = ft_split(color, ',');
	if (!rgb_tmp)
		error_perror_and_exit(NULL);
	r = convert_rgb_integer(rgb_tmp[0]);
	g = convert_rgb_integer(rgb_tmp[1]);
	b = convert_rgb_integer(rgb_tmp[2]);
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
