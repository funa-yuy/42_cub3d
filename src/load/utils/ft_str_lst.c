/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 04:25:10 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/24 23:54:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_strlst	*str_lstlast(const t_strlst *lst)
{
	t_strlst	*result;

	if (!lst)
		return (NULL);
	result = (t_strlst *)lst;
	while (result->next != NULL)
		result = result->next;
	return (result);
}

size_t	str_lstsize(const t_strlst *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_strlst	*str_lstnew(char *str)
{
	t_strlst	*new;

	new = (t_strlst *)malloc(sizeof(t_strlst));
	if (new == NULL)
		return (NULL);
	new->str = ft_strdup(str);
	if (!new->str)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	str_lstadd_back(t_strlst **lst, t_strlst *new)
{
	t_strlst	*tmp;

	if (!new)
		return ;
	else if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
