/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:09:05 by miyuu             #+#    #+#             */
/*   Updated: 2024/12/29 01:54:39 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*p;
	void	*fir;

	if (!lst || !f || !del)
		return (NULL);
	p = NULL;
	tmp = NULL;
	while (lst != NULL)
	{
		fir = f(lst->content);
		p = ft_lstnew(fir);
		if (p == NULL)
		{
			del(fir);
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp, p);
		lst = lst->next;
	}
	p = tmp;
	return (p);
}
