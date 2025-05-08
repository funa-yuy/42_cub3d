/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 04:25:10 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/08 11:21:22 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct	s_strlst
{
	char				*str;
	struct s_strlst		*next;
	struct s_strlst		*prev;
}				t_strlst;

size_t	str_lstsize(t_strlst *lst)
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

void	print_list(t_strlst *lst)
{
	while (lst)
	{
		printf("%s", lst->str);
		lst = lst->next;
	}
}

void	init_lst_data(t_data **data, char *file)
{
	int	fd;
	char	*line;
	t_strlst	*lines_list = NULL;
	t_strlst	*new;
	size_t		line_count;
	(void)data;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(ERR_SYSCALL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		new = str_lstnew(line);
		if (!new)
			exit(ERR_SYSCALL);
		str_lstadd_back(&lines_list, new);
		free(line);
		line = get_next_line(fd);
	}
	line_count = str_lstsize(lines_list);
	printf("line_count: %zu\n", line_count);
	print_list(lines_list);
}
