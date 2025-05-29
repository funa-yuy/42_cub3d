# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#              #
#    Updated: 2025/05/24 11:38:03 by miyuu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ====== Path for the program ======= #

NAME = cub3d
SRC_DIR = src
OBJ_DIR = bin
HEADER_DIR = include

# ========== Source Files =========== #
MAIN_SRC = src/main.c

LOAD_SRCS = \
		src/load/init_cubdata.c \
		src/load/normalize_cubdata.c \
		src/load/tokenize_lines.c \
		src/load/parse_to_data.c \
		src/load/fill_map.c \
		src/load/fill_images.c \
		src/load/fill_color.c \
		src/load/fill_player_position.c \
		src/load/free_data.c \
		src/load/utils/ft_str_lst.c \
		src/load/utils/free_str_array.c \
		src/load/utils/error_print_exit.c

#debugディレクトリは最終的に削除する
DEBUG_SRCS = \
		src/debug/debug_print_data.c \
		src/debug/debug_print_strlst.c \
		src/debug/debug_print_tokens_tmp.c \
		src/debug/debug_dprintf.c

SRC_WITHOUT_MAIN = \
		$(LOAD_SRCS) \
		$(DEBUG_SRCS)

SRC = \
	$(MAIN_SRC) \
	$(SRC_WITHOUT_MAIN)

# ============== Libft & GNL ============== #

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = lib/get_next_line
GNL_FILES = \
		get_next_line.c \
		get_next_line_utils.c

# ============== Compile  ============== #

CC = cc
CFLAGS = \
	-Wall -Wextra -Werror \
	-I$(HEADER_DIR) \
	-I$(MLX_DIR) \
	-I$(GNL_DIR) \
	-I$(LIBFT_DIR)

OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
		$(addprefix $(OBJ_DIR)/, $(GNL_FILES:.c=.o))

# ------- dedug ------- #

ifeq ($(shell uname), Darwin) #macの場合
	DEBUG_FLAGS = -DDEBUG -g -fsanitize=address -fsanitize=undefined
	VALGRIND =
else
	DEBUG_FLAGS = -DDEBUG -g
	VALGRIND = valgrind --leak-check=full --show-leak-kinds=all
endif

# ------- test ------- #

TEST_NAME = unit_test
TEST_DIR = test/unit-tests
TEST_OBJ_DIR = $(OBJ_DIR)/unit-tests
TEST_FILE = $(TEST_DIR)/dummy_test.c
# ここに、mustでコンパイルに含めたいファイルを追加していく
TEST_MUST_FILE = load/check_t_data_structure.c

ifneq ($(filter test,$(MAKECMDGOALS)),)
	TEST_ARG = $(filter-out test test-clean, $(MAKECMDGOALS))
endif
ifneq ($(TEST_ARG),)
	TEST_FILE = $(TEST_ARG) \
				$(TEST_DIR)/$(TEST_MUST_FILE)
endif

TEST_SRC = $(SRC_WITHOUT_MAIN)
TEST_OBJS = $(TEST_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
			$(TEST_FILE:$(TEST_DIR)/%.c=$(TEST_OBJ_DIR)/%.o) \
			$(addprefix $(OBJ_DIR)/, $(GNL_FILES:.c=.o))

# ============== minilibx  ============== #

# 使用しているOSを自動判定して、ダウンロードするminilibxを割り当てる
ifeq ($(shell uname), Darwin) #macの場合
	MINILIBX_URL = https://cdn.intra.42.fr/document/document/34596/minilibx_macos_opengl.tgz
	MINILIBX_TAR_GZ = minilibx_macos_opengl.tgz
	MLX_DIR = minilibx_opengl_20191021
	MLX_FLAGS =  -lmlx -framework OpenGL -framework AppKit
else
	MINILIBX_URL = https://cdn.intra.42.fr/document/document/34595/minilibx-linux.tgz
	MINILIBX_TAR_GZ = minilibx-linux.tgz
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -lmlx -lXext -lX11
endif

MLX = $(MLX_DIR)/libmlx.a

############### Build Rules ###############

.PHONY: all clean fclean re debug test test-clean

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)/*
	@$(MAKE) -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean; fi

fclean: test-clean clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@if [ -d "$(MLX_DIR)" ]; then $(RM) -r $(MLX_DIR); fi

re: fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

test: debug $(OBJ_DIR) $(TEST_OBJ_DIR) $(TEST_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TEST_NAME) $(TEST_OBJS) $(LIBFT) $(MLX_FLAGS) -L$(MLX_DIR)
	$(VALGRIND) ./$(TEST_NAME)

test-clean:
	rm -rf $(TEST_OBJ_DIR)
	rm -f $(TEST_NAME)

# ========== File Dependency ========== #

$(LIBFT): 
	@$(MAKE) -C $(LIBFT_DIR)


$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(MLX) -L$(MLX_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@


# minilibxのダウンロード & 展開 & コンパイル
# 1. minilibxが存在しない場合のみダウンロード
$(MINILIBX_TAR_GZ):
	@if [ ! -d "$(MLX_DIR)" ]; then curl -O $(MINILIBX_URL); fi

$(MLX_DIR): $(MINILIBX_TAR_GZ)
	tar xvzf $(MINILIBX_TAR_GZ)

# 2. アーカイブの展開とコンパイル(ダウンロードしたアーカイブは削除)
$(MLX): $(MLX_DIR)
	$(MAKE) -j4 -C $(MLX_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)


$(TEST_ARG):
	@:
