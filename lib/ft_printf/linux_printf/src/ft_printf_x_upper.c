/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:19:31 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/22 13:04:11 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	ft_printf_x_upper(unsigned int x)
{
	char	*base;
	char	result[9];
	int		i;

	base = "0123456789ABCDEF";
	result[8] = '\0';
	result[7] = base[x % 16];
	i = 7;
	while (x >= 16)
	{
		x /= 16;
		result[--i] = base[x % 16];
	}
	return (write(1, result + i, 8 - i));
}
