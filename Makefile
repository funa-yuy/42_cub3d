# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#              #
#    Updated: 2025/04/30 19:40:37 by miyuu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = bin
HEADER_DIR = include
LIBFT_DIR = lib/libft
PRINTF_DIR = lib/ft_printf
GNL_DIR = lib/get_next_line
MLX_DIR	= minilibx-linux
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11

# Source files
SRC_FILES = main.c


GNL_FILES = get_next_line.c \
			get_next_line_utils.c

# Header files
HEADER = $(HEADER_DIR)/cub3d.h


SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
		$(addprefix $(GNL_DIR)/, $(GNL_FILES))

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

# Build the program
all: $(OBJ_DIR) $(NAME)

# Create OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create the final executable
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(PRINTF) $(MLX)

# Compile each .c file into a .o file inside OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR) -c $< -o $@

# Clean all object files
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

# Clean all binary
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
# Rebuild
re: fclean all

.PHONY: all clean fclean re
