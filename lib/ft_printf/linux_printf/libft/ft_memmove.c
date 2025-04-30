/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:40:54 by mfunakos          #+#    #+#             */
/*   Updated: 2024/06/09 15:55:17 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			ptr_dst[i] = ptr_src[i];
	}
	else if (dst < src)
	{
		i = 0;
		while (len > i)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (ptr_dst);
}
