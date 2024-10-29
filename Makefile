NAME = push_swap

CHECKER = checker

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

SRC =	arrange.c\
	check.c\
	ft_atoi.c\
	ft_split.c\
	move_a.c\
	move_b.c\
	move_pair.c\
	movement.c\
	moves.c\
	push_swap.c\
	st_utils.c\
	stack_utils.c\
	utils.c

CHECKER_SRC =	check/checker.c\
	check/get_next_line.c\
	arrange.c\
	check.c\
	ft_atoi.c\
	ft_split.c\
	move_a.c\
	move_b.c\
	move_pair.c\
	movement.c\
	moves.c\
	push_swap.c\
	st_utils.c\
	stack_utils.c\
	utils.c

OBJ = $(SRC:.c=.o)

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)	

bonus: $(CHECKER)

$(NAME): $(CHECKER_OBJ)
	$(CC) $(CHECKER_OBJ) $(CFLAGS) -o $(CHECKER)	

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all
