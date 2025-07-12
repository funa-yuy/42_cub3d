# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 01:21:55 by miyuu             #+#    #+#              #
#    Updated: 2025/06/25 18:41:25 by mfunakos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ====== Path for the program ======= #

NAME = cub3d
SRC_DIR = src
OBJ_DIR = bin
HEADER_DIR = include

# ========== Source Files =========== #
MAIN_SRC = \
		src/main.c


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
		src/load/is_valid_map.c \
		src/load/utils/ft_str_lst.c \
		src/load/utils/free_str_array.c \
		src/load/utils/error_print_exit.c \
		src/load/utils/is_empty_line.c \
		src/load/utils/tokenize_utils.c \
		src/load/utils/calc_map_index.c


LINE_SEGMENT_SRCS = \
		src/line_segment/is_zero_vector.c\


VEC_SRCS = \
		src/vec/eq_f32x4.c\
		src/vec/linear_solver.c\
		src/vec/add_f32x4.c\
		src/vec/sub_f32x4.c\
		src/vec/mul_f32x4.c\
		src/vec/div_f32x4.c\
		src/vec/scalar_f32x4.c\
		src/vec/f32x4_wxyz.c\
		src/vec/init_f32x4.c\
		src/vec/print_f32x4.c\
		src/vec/f32x4_to_struct.c\
		src/vec/cross_point.c \
		src/vec/norm_f32x4.c\
		src/vec/f32x4_has_error.c\
		src/vec/float_eq.c\


FRAME_SRC = \
		src/frames/axis_x_frames.c\
		src/frames/axis_y_frames.c\
		src/frames/clear_frames.c\
		src/frames/get_line_segment_arr.c\
		src/frames/get_map_type.c\
		src/frames/get_wall_type.c\
		src/frames/print_line_segment.c\


RENDER_SRC = \
		src/render/base.c\
		src/render/screen.c\
		src/render/player.c\
		src/render/get_cross_wall.c\
		src/render/draw_vertical_line.c\


MOVE_SRCS = \
		src/move/can_move_position.c \
		src/move/update_angle.c \
		src/move/update_position.c \
		src/move/handle_key_input.c


DEBUG_SRCS = \
		src/debug/debug_print_data.c \
		src/debug/debug_print_strlst.c \
		src/debug/debug_print_tokens_tmp.c \
		src/debug/debug_dprintf.c


SRC_WITHOUT_MAIN = \
		$(LOAD_SRCS) \
		$(DEBUG_SRCS)\
		$(MOVE_SRCS)\
		$(VEC_SRCS)\
		$(LINE_SEGMENT_SRCS)\
		$(FRAME_SRC)\
		$(RENDER_SRC)


SRC = \
		$(MAIN_SRC) \
		$(SRC_WITHOUT_MAIN) \
		$(GNL_FILES)


# ============== Libft & GNL ============== #

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = lib/get_next_line
GNL = $(GNL_DIR)/get_next_line.o

# ============== Compile  ============== #

CC = cc
CFLAGS = \
	-Wall -Wextra -Werror -g\
	-I$(HEADER_DIR) \
	-I$(MLX_DIR) \
	-I$(GNL_DIR) \
	-I$(LIBFT_DIR) \


OBJS = \
	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \

# ------- test ------- #

TEST_NAME = unit_test

TEST_DIR = test/unit-tests
TEST_OBJ_DIR = $(OBJ_DIR)/unit-tests
# ここに、mustでコンパイルに含めたいファイルを追加していく
TEST_MUST_FILE = test/unit-tests/load/check_t_data_structure.c

TEST_SRC = $(SRC_WITHOUT_MAIN)
TEST_OBJS = \
		$(TEST_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \

# 環境差異
ifeq ($(shell uname), Darwin) #macの場合
	# ---------- dedug ---------- #
	DEBUG_FLAGS = -DDEBUG -g -fsanitize=address -fsanitize=undefined
	VALGRIND =
	# ------- mlx setting ------- #
	MINILIBX_TAR_GZ = minilibx_macos_opengl.tgz
	MLX_DIR = minilibx_opengl_20191021
	MLX_FLAGS =  -lmlx -framework OpenGL -framework AppKit
else
	# ------- dedug ------- #
	DEBUG_FLAGS = -DDEBUG -g
	VALGRIND = valgrind --leak-check=full --show-leak-kinds=all
	# ------- mlx setting ------- #
	MINILIBX_TAR_GZ = minilibx-linux.tgz
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -lmlx -lXext -lX11
	# cpu固有の命令
	CFLAGS += -msse4.1
endif

MLX = $(MLX_DIR)/libmlx.a

############### Build Rules ###############

.PHONY: all clean fclean re debug test test-clean

all: $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: test-clean clean
	rm -f $(NAME)
	rm -rf $(MINILIBX_TAR_GZ)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: clean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

test: TEST_SRC += $(filter-out test test-clean, $(MAKECMDGOALS))
test: TEST_SRC += $(TEST_MUST_FILE)
test: CFLAGS += $(DEBUG_FLAGS)
test: $(MLX) $(OBJ_DIR) $(TEST_OBJS) $(LIBFT) $(GNL)
	$(CC) \
		$(CFLAGS) \
		-o $(TEST_NAME) \
		$(TEST_OBJS) $(GNL) $(LIBFT) $(MLX)\
		$(MLX_FLAGS) -lm -L$(MLX_DIR)
	$(VALGRIND) ./$(TEST_NAME)

test-clean:
	rm -rf $(TEST_OBJ_DIR)
	rm -f $(TEST_NAME)

# ========== File Dependency ========== #

$(NAME): $(MLX) $(GNL) $(OBJS) $(LIBFT)
	$(CC) \
		$(CFLAGS) \
		-o $(NAME) \
		$(OBJS) $(GNL) $(LIBFT) $(MLX) \
		$(MLX_FLAGS) -lm -L$(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(TEST_OBJ_DIR)/%.o: $(TEST_OBJ_DIR) $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# minilibxの存在確認 & 展開 & コンパイル
# 1. minilibxが存在しない場合、エラーになる
$(MLX_DIR):
	@if [ ! -d "$(MLX_DIR)" ] && [ ! -f "$(MINILIBX_TAR_GZ)" ]; then \
		echo "minilibx linuxを手動でinstallしてください"; \
		exit 1; \
	fi
	tar xvzf $(MINILIBX_TAR_GZ)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

# 2. アーカイブの展開とコンパイル(ダウンロードしたアーカイブは削除)
$(MLX): $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

