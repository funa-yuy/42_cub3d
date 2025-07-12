/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_eq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 08:08:36 by tmuranak          #+#    #+#             */
/*   Updated: 2025-07-12 08:08:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

bool	float_equal(float a, float b, float epsilon)
{
	return (fabsf(a - b) < epsilon);
}

bool	float_less_equal(float a, float b, float epsilon)
{
	return ((a < b) || float_equal(a, b, epsilon));
}
