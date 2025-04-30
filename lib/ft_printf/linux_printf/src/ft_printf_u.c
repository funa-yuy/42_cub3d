/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:19:31 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/21 01:19:33 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	ft_printf_u(unsigned int u)
{
	char	result[11];
	int		i;

	result[10] = '\0';
	result[9] = u % 10 + '0';
	i = 9;
	while (u >= 10)
	{
		u /= 10;
		result[--i] = u % 10 + '0';
	}
	return (write(1, result + i, 10 - i));
}
