# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#              #
#    Updated: 2025/05/07 18:51:43 by miyuu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------ Path for the program ------- #

NAME = cub3d
SRC_DIR = src
OBJ_DIR = bin
HEADER_DIR = include
HEADER = $(HEADER_DIR)/cub3d.h

# ここに追加していく
SRC_FILES = main.c \
			init_map_data.c \
			ft_strcmp.c \
			ft_strncmp.c

# ---------- Libft & GNL ---------- #

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = lib/get_next_line
GNL_FILES = get_next_line.c \
			get_next_line_utils.c

# ---------- Compile  ---------- #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #todo: デバック用に-gを追加

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
		$(addprefix $(GNL_DIR)/, $(GNL_FILES))
VPATH = $(SRC_DIR) $(GNL_DIR)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

# ---------- minilibx  ---------- #
# 使用しているOSを自動判定して、ダウンロードするminilibxを割り当てる
ifeq ($(shell uname), Darwin) #macの場合
	MINILIBX_URL = https://cdn.intra.42.fr/document/document/32194/minilibx_opengl.tgz
	MINILIBX_TAR_GZ = minilibx_opengl.tgz
	MLX_DIR = minilibx_opengl_20191021
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MINILIBX_URL = https://cdn.intra.42.fr/document/document/32193/minilibx-linux.tgz
	MINILIBX_TAR_GZ = minilibx-linux.tgz
	MLX_DIR = minilibx-linux
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11
endif


############### Build Rules ###############
.PHONY: all clean fclean re

all: $(OBJ_DIR) $(MLX) $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@if [ -d "$(MLX_DIR)" ]; then $(RM) -r $(MLX_DIR); fi

re: fclean all

# ---------- File Dependency ---------- #
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(MLX_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR) -c $< -o $@

# minilibxのダウンロード & 展開 & コンパイル
# 1. minilibxが存在しない場合のみダウンロード
$(MINILIBX_TAR_GZ):
	@if [ ! -d "$(MLX_DIR)" ]; then curl -O $(MINILIBX_URL); fi
# 2. アーカイブの展開とコンパイル(ダウンロードしたアーカイブは削除)
$(MLX): $(MINILIBX_TAR_GZ)
	@if [ ! -d "$(MLX_DIR)" ]; then tar xvzf $(MINILIBX_TAR_GZ); fi
	$(MAKE) -j4 -C $(MLX_DIR)
	@rm -f $(MINILIBX_TAR_GZ)
