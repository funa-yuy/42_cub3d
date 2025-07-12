/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_segment_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 08:05:36 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-12 08:05:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_segment.h"
#include <stdlib.h>

t_line_segment	*get_line_segment_arr(size_t width, size_t height)
{
	return (malloc(sizeof(t_line_segment) * width * height));
}
