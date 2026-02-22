NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror


HEADERS     = push_swap.h 

SRC         = bench_des_strategy.c bench_op.c bench.c disorder.c extra.c \
              flag.c ft_lib.c main.c op_push.c op_rotate.c op_rrotate.c op_swap.c \
              parse.c select_algorithm.c sort_complex.c sort_medium.c sort_normalize.c \
              sort_simple.c number_check.c\

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
