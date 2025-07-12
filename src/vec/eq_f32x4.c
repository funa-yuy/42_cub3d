/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq_f32x4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 08:07:56 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-12 08:07:56 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <immintrin.h>
#include <stdbool.h>

bool	eq_f32x4(t_f32x4 a, t_f32x4 b)
{
	return (_mm_movemask_ps(_mm_cmpeq_ps(a, b)) == 0b1111);
}
