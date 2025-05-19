/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:42:33 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/19 12:50:17 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_perror_and_exit(char *str)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	perror(str);
	exit(1);
}

void	error_print_and_exit(char *str)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	exit(1);
}
