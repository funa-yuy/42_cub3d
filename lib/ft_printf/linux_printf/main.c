/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:07:51 by miyuu             #+#    #+#             */
/*   Updated: 2024/08/01 17:10:48 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{

int count = 0;

	count = printf("\x1b[39mHello, World!\n");
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mHello, World!\n");
	printf("count = %d\n", count);
	count = printf("\x1b[39m");
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m");
	printf("count = %d\n", count);
	count = printf("\x1b[39mHello, World!\n""1""2\n");
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mHello, World!\n""1""2\n");
	printf("count = %d\n", count);

	count = printf("\x1b[39m\n");
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m\n");
	printf("count = %d\n", count);

	printf("\x1b[39mBefore control characters\n");
	count = printf("\001\002\007\vv\010\f\r\n");
	printf("After control characters\n");
	printf("count = %d\n", count);
	ft_printf("\x1b[32mBefore control characters\n");
	count = ft_printf("\001\002\007\vv\010\f\r\n");
	ft_printf("After control characters\n");
	printf("count = %d\n", count);

	count = printf("\x1b[39m\x01\x02\a\v\b\f\r\n");
	printf("count_printf = %d\n", count);
	count = ft_printf("\x1b[32m\x01\x02\a\v\b\f\r\n");
	printf("count_ft_printf =\x1b[32m %d\n", count);

	count = printf("\x1b[39m%%");
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%%");
	printf("count = %d\n", count);


printf("\x1b[31m\n以下%%c\n");
	char	c = 'i';
	count = printf("\x1b[39mor:%%c = %c\n", c);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%c = %c\n", c);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%c -> %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", '1', '2', '3', '4', '5', '6', '7', 'i', 'I', 'B', 'a');
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%c -> %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", '1', '2', '3', '4', '5', '6', '7', 'i', 'I', 'B', 'a');
	printf("count = %d\n", count);

	count = printf("\x1b[39m%%%c", 'x');
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%%%c", 'x');
	printf("count = %d\n", count);


	count = printf("\x1b[39m%c%c%c", 'a', '\t', 'b');
	printf("count = %d\n", count);
	count =  ft_printf("\x1b[32m%c%c%c", 'a', '\t', 'b');
	printf("count = %d\n", count);

	count = printf("\x1b[39m%c%c%c", 'c', 'b', 'a');
	printf("count = %d\n", count);
	count =  ft_printf("\x1b[32m%c%c%c", 'c', 'b', 'a');
	printf("count = %d\n", count);

printf("\x1b[31m\n以下%%s\n");
	char	s[] = "Hello, World!";
	count = printf("\x1b[39mor:%%s = %s\n", s);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%s = %s\n", s);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%s -> %s, %s, %s, %s\n", "1", "42Tokyo", "空白　。", "改行\n");
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%s -> %s, %s, %s, %s\n", "1", "42Tokyo", "空白　。", "改行\n");
	printf("count = %d\n", count);

printf("\x1b[31m\n以下(%%s, (char *)NULL)\n");
	count = printf("\x1b[39m%s", (char *)NULL);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%s", (char *)NULL);
	printf("count = %d\n", count);

	count = printf("\x1b[39m%ss%ss%ss", "And ", "some other", "joined");
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%ss%ss%ss", "And ", "some other", "joined");
	printf("count = %d\n", count);


printf("\x1b[31m\n以下%%p\n");
	void	*p_3 = "42";
	count = printf("\x1b[39mor:%%p = %p\n", p_3);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%p = %p\n", p_3);
	printf("count = %d\n", count);

	count = printf("\x1b[39m0x%p-", (void *)ULONG_MAX);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m0x%p-", (void *)ULONG_MAX);
	printf("count = %d\n", count);

	count = printf("\x1b[39m%p, %p, %p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%p, %p, %p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("count = %d\n", count);

	int	p_4 = 1234567;
	count = printf("\x1b[39mor:%%p = %p\n", &p_4);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%p = %p\n", &p_4);
	printf("count = %d\n", count);

		void	*p_5 = 0;
	count = printf("\x1b[39mor:%%p = %p\n", p_5);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%p = %p\n", p_5);
	printf("count = %d\n", count);

	count = printf("\x1b[39mor:%%p = %p\n", (void *)INT_MAX);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%p = %p\n", (void *)INT_MAX);
	printf("count = %d\n", count);

printf("\x1b[31m\n以下%%d\n");
	char	d_char = 10;
	count = printf("\x1b[39mor:%%d_char = %d\n", d_char);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%d_char = %d\n", d_char);
	printf("count = %d\n", count);

	int	d_int = 100;
	count = printf("\x1b[39mor:%%d_int = %d\n", d_int);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%d_int = %d\n", d_int);
	printf("count = %d\n", count);

	count = printf("\x1b[39m%d", 0);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%d", 0);
	printf("count = %d\n", count);
	count = printf("\x1b[39m%i", 0);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%i", 0);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", -1);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", -1);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 1);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 1);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 9);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 9);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 10);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 10);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 11);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 11);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 15);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 15);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 16);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 16);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 17);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 17);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 99);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 99);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 100);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 100);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", 101);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", 101);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", -9);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", -9);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", -10);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", -10);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", -11);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", -11);
	printf("count = %d\n", count);
	count = printf("\x1b[39m %d ", -14);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m %d ", -14);
	printf("count = %d\n", count);

printf("\x1b[31m\n以下(%%d, 0)\n");
	count = printf("\x1b[39m%d", 0);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%d", 0);
	printf("count = %d\n", count);

printf("\x1b[31m\n以下%%i\n");
	int	i = 123;
	int i_2 = -+000456;
	count = printf("\x1b[39mor:%%iは　= %iです。%%i = %i\n", i, i_2);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%iは　= %iです。%%i = %i\n", i, i_2);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	printf("count = %d\n", count);

printf("\x1b[31m\n以下%%u\n");
	unsigned int	u_unint = 0;
	unsigned int	u_unint_2 = 456;
	unsigned int	u_unint_3 = -+456;
	unsigned int	u_unint_4 = 4294967295;
	unsigned int	u_unint_5 = 2147483647;
	count = printf("\x1b[39mor:%%u_unint = %u\n", u_unint);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unint = %u\n", u_unint);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%u_unint_2 = %u\n", u_unint_2);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unint_2 = %u\n", u_unint_2);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%u_unint_3 = %u\n", u_unint_3);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unint_3 = %u\n", u_unint_3);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%u_unint_4 = %u\n", u_unint_4);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unint_4 = %u\n", u_unint_4);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%u_unint_4 = %u\n", u_unint_5);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unint_4 = %u\n", u_unint_5);
	printf("count = %d\n", count);

	unsigned short	u_unshort = 0;
	unsigned short	u_unshort_2 = 456;
	unsigned short	u_unshort_3 = -+456;
	unsigned short	u_unshort_4 = 65535;
	count = printf("\x1b[39mor:%%u_unshort = %u\n", u_unshort);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unshort = %u\n", u_unshort);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%u_unshort_2 = %u\n", u_unshort_2);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unshort_2 = %u\n", u_unshort_2);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%u_unshort_3 = %u\n", u_unshort_3);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unshort_3 = %u\n", u_unshort_3);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%u_unshort_4 = %u\n", u_unshort_4);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%u_unshort_4 = %u\n", u_unshort_4);
	printf("count = %d\n", count);

	count = printf("\x1b[39mdgs%uxx", 10);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mdgs%uxx", 10);
	printf("count = %d\n", count);

	count = printf("\x1b[39m%u%uu%u", 1, 2, -3);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%u%uu%u", 1, 2, -3);
	printf("count = %d\n", count);

printf("\x1b[31m\n以下%%x\n");
	int	x_int = 0;
	int	x_int_1 = 10;
	int	x_int_2 = 42;
	int	x_int_3 = -420;
	count = printf("\x1b[39mor:%%x_int = %x\n", x_int);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_int = %x\n", x_int);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%x_int_1 = %x\n", x_int_1);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_int_1 = %x\n", x_int_1);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%x_int_2 = %x\n", x_int_2);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_int_2 = %x\n", x_int_2);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%x_int_3 = %x\n", x_int_3);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_int_3 = %x\n", x_int_3);
	printf("count = %d\n", count);
	// printf("int %%x_int = %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x\n", x_int, 1, 2, 3, 10, 16, 42, '1', '2', '3', '10', '16', '42');

	short	x_short = 10;
	short	x_short_1 = 10;
	short	x_short_2 = 42;
	short	x_short_3 = -420;
	count = printf("\x1b[39mor:%%x_short = %x\n", x_short);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_short = %x\n", x_short);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%x_short_1 = %x\n", x_short_1);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_short_1 = %x\n", x_short_1);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%x_short_2 = %x\n", x_short_2);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_short_2 = %x\n", x_short_2);
	printf("count = %d\n", count);
	count = printf("\x1b[39mor:%%x_short_3 = %x\n", x_short_3);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_short_3 = %x\n", x_short_3);
	printf("count = %d\n", count);

	unsigned int	x_unint = 10;
	count = printf("\x1b[39mor:%%x_unsigned int  = %x\n", x_unint);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_unsigned int  = %x\n", x_unint);
	printf("count = %d\n", count);

	unsigned short	x_unshort = 10;
	count = printf("\x1b[39mor:%%x_unsigned short  = %x\n", x_unshort);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%x_unsigned short  = %x\n", x_unshort);
	printf("count = %d\n", count);

	count = printf("\x1b[39m%x%xx%x", 1, 2, -3);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%x%xx%x", 1, 2, -3);
	printf("count = %d\n", count);

	count = printf("\x1b[39m%x", INT_MAX);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%x", INT_MAX);
	printf("count = %d\n", count);
	count = printf("\x1b[39m%x", UINT_MAX);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%x", UINT_MAX);
	printf("count = %d\n", count);
	count = printf("\x1b[39m%x", INT_MIN);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%x", INT_MIN);
	printf("count = %d\n", count);
	count = printf("\x1b[39m%x", INT_MIN+1);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%x", INT_MIN+1);
	printf("count = %d\n", count);


	int	X = 10;
	count = printf("\x1b[39mor:%%X = %X\n", X);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%%X = %X\n", X);
	printf("count = %d\n", count);

	count = printf("\x1b[39mor:%% = %%\n");
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32mft:%% = %%\n");
	printf("count = %d\n", count);

	count = printf("\x1b[39m%X", INT_MAX);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%X", INT_MAX);
	printf("count = %d\n", count);
	count = printf("\x1b[39m%X", UINT_MAX);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%X", UINT_MAX);
	printf("count = %d\n", count);
	count = printf("\x1b[39m%X", INT_MIN);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%X", INT_MIN);
	printf("count = %d\n", count);
	count = printf("\x1b[39m%X", INT_MIN+1);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32m%X", INT_MIN+1);
	printf("count = %d\n", count);



	count = printf("\x1b[39ma%s'`i:%x)79%Xk%dS\f_%i8cP%Xg%dT<y&Ur !e", "{UEw3tOrYp/Z*e%e^XZ23Y@wj\nv", -1823292835, 1620794947, 818754188, -1102400945, 33983181, -550375570);
	printf("count = %d\n", count);
	count = ft_printf("\x1b[32ma%s'`i:%x)79%Xk%dS\f_%i8cP%Xg%dT<y&Ur !e", "{UEw3tOrYp/Z*e%e^XZ23Y@wj\nv", -1823292835, 1620794947, 818754188, -1102400945, 33983181, -550375570);
	printf("count = %d\n", count);


		// printf("\n以下%%p\n");
	// void 	*p = "16";
	// printf("or:%%p = %p \n", p);
	// printf("or:%%s = %s \n", p);
	// printf("or:%%i = %i \n", p);
	// printf("or:%%d = %d \n", p);
	// printf("or:%%x = %x \n", &p);
	// printf("or:%%X = %X \n", &p);
	// printf("or:%%p = %p \n", &p);

	// printf("\n以下%%p_2\n");
	// void	*p_2 = "hello";
	// printf("or:%%p = %p \n", p_2);
	// printf("or:%%s = %s \n", p_2);
	// printf("or:%%i = %i \n", p_2);
	// printf("or:%%d = %d \n", p_2);
	// printf("or:%%x = %x \n", &p_2);
	// printf("or:%%X = %X \n", &p_2);
	// printf("or:%%p = %p \n", &p_2);

	// ft_printf("ft:%%p = %p \n", p);
printf("\x1b[31m\n以下NULL\n");
	printf("\x1b[39m%c\n", NULL);
	ft_printf("\x1b[32m%c\n", NULL);
	printf("\x1b[39m%s\n", NULL);
	ft_printf("\x1b[32m%s\n", NULL);
	printf("\x1b[39m%p\n", NULL);
	ft_printf("\x1b[32m%p\n", NULL);
	printf("\x1b[39m%d\n", NULL);
	ft_printf("\x1b[32m%d\n", NULL);
	printf("\x1b[39m%i\n", NULL);
	ft_printf("\x1b[32m%i\n", NULL);
	printf("\x1b[39m%u\n", NULL);
	ft_printf("\x1b[32m%u\n", NULL);
	printf("\x1b[39m%x\n", NULL);
	ft_printf("\x1b[32m%x\n", NULL);
	printf("\x1b[39m%X\n", NULL);
	ft_printf("\x1b[32m%X\n", NULL);
	printf("\x1b[39m%%\n");
	ft_printf("\x1b[32m%%\n");

	count = printf("\x1b[39mor:%%s -> %s, %s, %s, %s\n", "", "42Tokyo", "空白　。", "改行\n");
	count = ft_printf("\x1b[32mft:%%s -> %s, %s, %s, %s\n", "", "42Tokyo", "空白　。", "改行\n");
	printf("\n");

	count = printf("\x1b[39mint %%x_int = %x%x%x%x%x%x%x%x%x%x%x%x%x\n", x_int, 1, 2, 3, 10, 16, 42, '1', '2', '3', '10', '16', '42');
	printf("count = %d\n", count);

	count = ft_printf("\x1b[32mint %%x_int = %x%x%x%x%x%x%x%x%x%x%x%x%x\n", x_int, 1, 2, 3, 10, 16, 42, '1', '2', '3', '10', '16', '42');
	printf("count = %d\n", count);


	count = printf("안녕하세요\n");
	count = printf("😀\n");
	count = printf("\x1b[35m\xef\xa3\xbf\n");
	count = printf("\xe3\xbd\x88\xe3\xbd\xb1\xf0\xad\x9e\xbd\xef\xa3\xbf\xe3\xbd\x91\n");
	return (0);
}


// • %c 1 文字を出力します。
// • %s 文字列を出力します (一般的な C 規約で定義されています)。
// • %p void * ポインター引数は 16 進形式で出力する必要があります。
// • %d 10 進数 (基数 10) を出力します。
// • %i 10 進数の整数を出力します。
// • %u 符号なし 10 進数 (基数 10) を出力します。
// • %x 16 進数 (基数 16) 小文字形式で数値を出力します。
// • %X 16 進数 (基数 16) 大文字形式で数値を出力します。
// • %% パーセント記号を出力します

