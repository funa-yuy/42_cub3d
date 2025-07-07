/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_segment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 09:55:01 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-07 09:55:01 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frames.h"
#include "line_segment.h"
#include "vec.h"
#include <stdlib.h>
#include <unistd.h>

int	print_line_segment(char *str, t_line_segment ls)
{
	print_f32x4(str, ls.s);
	print_f32x4(str, ls.e);
	return (0);
}

int	print_walls_line_segment_axis_y(t_axis_y_frames *x_frames)
{
	size_t	i;

	i = 0;
	while (i < x_frames->width * x_frames->height)
	{
		if (!is_zero_vector(x_frames->buf[i]))
		{
			debug_dprintf(STDERR_FILENO, "x:%d y:%d \n", i % x_frames->width, i
				/ x_frames->width);
			print_line_segment("ll: ", x_frames->buf[i]);
		}
		i += 1;
	}
	return (0);
}
