NAME	=	push_swap
CC		=	clang
FLAGS	=	-Wall -Werror -Wextra
INCS	=	$(addprefix header/, push_swap.h)
OBJS	=	$(SRCS:.c=.o)

SRCS	=	srcs/main.c				\
			srcs/error.c			\
			srcs/ft_utils.c			\
			srcs/get_big.c			\
			srcs/operateur_a.c		\
			srcs/operateur_b.c		\
			srcs/operateur_utils.c	\
			srcs/parsing.c			\
			srcs/sort_big.c			\
			srcs/sort_big_2.c		\
			srcs/sort_small.c

all: $(NAME)

$(NAME): ${OBJS} $(INCS)
	$(CC) $(FLAGS) -I header -o $(NAME) $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -I header -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all