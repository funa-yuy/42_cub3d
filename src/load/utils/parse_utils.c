/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:20:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/25 00:21:22 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_spaces_both_ends(const char *str)
{
	char	*dst;
	size_t	start;
	size_t	end;
	size_t	j;
	size_t	len;

	start = 0;
	while (ft_isspace(str[start]))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_isspace(str[end - 1]))
		end--;
	len = end - start;
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		error_perror_and_exit(NULL);
	j = 0;
	while (len > j)
	{
		dst[j] = str[start + j];
		j++;
	}
	dst[len] = '\0';
	return (dst);
}

size_t	get_trimmed_lstsize(const t_strlst *lst)
{
	size_t		total_size;
	size_t		empty_num;
	t_strlst	*last_lst;

	if (!lst)
		return (0);
	total_size = str_lstsize(lst);
	empty_num = 0;
	last_lst = str_lstlast(lst);
	while (last_lst && is_empty_line(last_lst->str))
	{
		last_lst = last_lst->prev;
		empty_num++;
	}
	return (total_size - empty_num);
}

char	*strdup_trim_nl(const char *str)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		len--;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		error_perror_and_exit(NULL);
	i = 0;
	while (len > i)
	{
		dst[i] = str[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
