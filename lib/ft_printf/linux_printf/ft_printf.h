/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:48:53 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/17 21:21:30 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf_c(int c);
int	ft_printf_s(char *s);
int	ft_printf_p(void *p);
int	ft_printf_d(int d);
int	ft_printf_u(unsigned int u);
int	ft_printf_x(unsigned int x);
int	ft_printf_x_upper(unsigned int x);
int	ft_printf_format(const char *str, va_list ap, size_t i);
int	ft_printf(const char *str, ...);

#endif
