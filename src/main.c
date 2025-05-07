/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:44:56 by mfunakos          #+#    #+#             */
/*   Updated: 2025/05/07 13:08:17 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	(void) argv;
	printf("コンパイルできた〜〜〜\n");
	if (argc != 2)
	{
		write(STDERR_FILENO, "Invalid number of arguments.\n", ft_strlen("Invalid number of arguments.\n"));
		return (1);
	}
	return (0);
}
