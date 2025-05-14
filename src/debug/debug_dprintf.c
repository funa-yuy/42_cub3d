/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_dprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:01:30 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/14 20:45:38 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdarg.h>

#ifdef DEBUG

int	debug_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		rv;

	va_start(args, format);
	rv = vdprintf(fd, format, args);
	va_end(args);
	return (rv);
}
#else

int	debug_dprintf(int fd, const char *format, ...)
{
	(void) fd;
	(void) format;
	return (0);
}
#endif
