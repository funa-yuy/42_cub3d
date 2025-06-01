
# ====== Path for the program ======= #
CC = cc
RM = rm -rf

NAME = get_next_line.o

# ========== Source Files =========== #
SRC = \
      get_next_line.c \


# ============== Compile  ============== #

CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:%.c=%.o)

############### Build Rules ###############

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(NAME)


clean:

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
