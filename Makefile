# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#              #
#    Updated: 2025/05/07 00:05:29 by miyuu            ###   ########.fr        #
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
GNL_DIR = lib/get_next_line
MLX_DIR	= minilibx-linux
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11

# Source files
SRC_FILES = main.c

GNL_FILES = get_next_line.c \
			get_next_line_utils.c

# Header files
HEADER = $(HEADER_DIR)/cub3d.h

# Source file list
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
		$(addprefix $(GNL_DIR)/, $(GNL_FILES))
VPATH = $(SRC_DIR) $(GNL_DIR)

# Object file list
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Build the program
all: $(OBJ_DIR) $(NAME)

# Create OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create the final executable
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(MLX)

# Compile
$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(MLX_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
