CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I./include

NAME = push_swap

LIBFTD = Libft/libft.a

SRC_PATH =	push_swap.c			\
			check_args.c		\
			create_stack_a.c	\

SRC = $(addprefix src/,$(SRC_PATH))

OBJ	= $(SRC:.c=.o)

all : libft $(NAME)

clean :
	$(RM) $(OBJ)
	make clean -C Libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C Libft

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(SRC) $(LIBFTD)

libft :
	make -C Libft

re : fclean all

.PHONY : all clean re