/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_frames.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 09:54:03 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-07 09:54:03 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frames.h"

int	clear_axis_x_frames(t_axis_x_frames *frame_x)
{
	free(frame_x->buf);
	free(frame_x);
	return (0);
}

int	clear_axis_y_frames(t_axis_y_frames *frame_y)
{
	free(frame_y->buf);
	free(frame_y);
	return (0);
}
