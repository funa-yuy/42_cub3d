/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:09:05 by miyuu             #+#    #+#             */
/*   Updated: 2024/06/09 15:55:11 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*p;
	void	*fir;

	p = NULL;
	tmp = NULL;
	if (!lst || !f || !del)
		return (NULL);
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
