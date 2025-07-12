/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 08:10:24 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-12 08:10:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_segment.h"
#include "vec.h"
#include <stdbool.h>

bool	is_zero_vector(t_line_segment a)
{
	return (eq_f32x4(a.e, a.s));
}
