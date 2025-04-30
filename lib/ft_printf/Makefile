# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 17:00:40 by mfunakos          #+#    #+#              #
#    Updated: 2024/07/14 02:00:37 by miyuu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT	= ./libft/libft.a

SRCS =	ft_printf.c \
		src/ft_printf_c.c \
		src/ft_printf_s.c \
		src/ft_printf_p.c \
		src/ft_printf_d.c \
		src/ft_printf_u.c \
		src/ft_printf_x.c \
		src/ft_printf_x_upper.c

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
