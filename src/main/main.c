/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:44:56 by mfunakos          #+#    #+#             */
/*   Updated: 2025/05/08 10:13:45 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	printf("コンパイルできた〜〜〜\n");
	if (argc != 2)
	{
		write(STDERR_FILENO, "Invalid number of arguments.\n", ft_strlen("Invalid number of arguments.\n"));
		return (1);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(ERR_SYSCALL);
	init_data(&data, argv[1]);
	return (0);
}
