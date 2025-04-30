/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:52:36 by miyuu             #+#    #+#             */
/*   Updated: 2024/06/09 15:55:26 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	j = dst_len;
	i = 0;
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	if (dst_len < dstsize - 1 && dstsize > 0)
	{
		while (src[i] != '\0' && dst_len + i < dstsize - 1)
		{
			dst[j] = src [i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (dst_len + src_len);
}
