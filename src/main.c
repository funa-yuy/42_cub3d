/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:44:56 by mfunakos          #+#    #+#             */
/*   Updated: 2025/05/11 15:59:05 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Invalid number of arguments.\n", \
			ft_strlen("Invalid number of arguments.\n"));
		return (1);
	}
	data = init_cubdata(argv[1]);
	debug_print_data((t_data *)data);
	//描写
	free_data(data);
	return (0);
}
