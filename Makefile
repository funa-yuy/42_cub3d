# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#              #
#    Updated: 2025/05/06 21:07:02 by miyuu            ###   ########.fr        #
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

# Source files
SRC_FILES = main.c \
			init_map_data.c

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

# Platform-specific configurations
# Linux configuration
LINUX_MLX_DIR = minilibx-linux

# macOS configuration
MAC_MINILIBX_URL := https://cdn.intra.42.fr/document/document/32194/minilibx_opengl.tgz
MAC_MINILIBX_TAR_GZ := minilibx_opengl.tgz
MAC_MLX_DIR := minilibx_opengl_20191021

# Platform detection and configuration
ifeq ($(shell uname), Darwin)
    MLX_DIR = $(MAC_MLX_DIR)
    MLX = $(MAC_MLX_DIR)/libmlx.a
    MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
    PLATFORM = mac
else
    MLX_DIR = $(LINUX_MLX_DIR)
    MLX = $(LINUX_MLX_DIR)/libmlx.a
    MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11
    PLATFORM = linux
endif


# Build targets
all: $(OBJ_DIR) $(NAME)

mac: PLATFORM = mac
mac: $(OBJ_DIR) $(MLX) $(NAME)

# Create OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create the final executable
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR); fi
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT)

# Compile
$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(MLX_DIR) -I$(GNL_DIR) -c $< -o $@

# macOS-specific minilibx download and extraction
$(MAC_MINILIBX_TAR_GZ):
	curl -O $(MAC_MINILIBX_URL)

$(MLX): $(MAC_MINILIBX_TAR_GZ)
	tar xvzf $(MAC_MINILIBX_TAR_GZ)
	$(MAKE) -j4 -C $(MAC_MLX_DIR)

# Clean targets
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
ifeq ($(PLATFORM), mac)
	@if [ -d "$(MAC_MLX_DIR)" ]; then $(MAKE) -C $(MAC_MLX_DIR) clean; fi
	@if [ -f "$(MAC_MINILIBX_TAR_GZ)" ]; then $(RM) $(MAC_MINILIBX_TAR_GZ); fi
endif

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
ifeq ($(PLATFORM), mac)
	@if [ -d "$(MAC_MLX_DIR)" ]; then $(RM) -r $(MAC_MLX_DIR); fi
	@if [ -f "$(MAC_MINILIBX_TAR_GZ)" ]; then $(RM) $(MAC_MINILIBX_TAR_GZ); fi
endif

re: fclean all

.PHONY: all clean fclean re mac
