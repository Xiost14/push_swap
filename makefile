MAME	=	push_swap
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
OBJS	=	${SRC:.c=.o}
HEAD	=	header/

SRC		=	srcs/main.c				\
			srcs/bigger.c			\
			srcs/check.c			\
			srcs/fill.c				\
			srcs/find.c				\
			srcs/ft_abs.c			\
			srcs/ft_free_array.c	\
			srcs/ft_free.c			\
			srcs/ft_strcmp.c		\
			srcs/initialisation.c	\
			srcs/list_utils_1.c		\
			srcs/list_utils_2.c		\
			srcs/norm.c				\
			srcs/operateur_p.c		\
			srcs/operateur_r.c		\
			srcs/operateur_s.c		\
			srcs/parsing.c			\
			srcs/ps_atoll.c			\
			srcs/short.c			\
			srcs/ft_putstr_fd.c		\
			srcs/ft_strlen.c		\
			srcs/ft_strdup.c		\
			srcs/ft_split.c			\
			srcs/ft_bzero.c			\
			srcs/ft_putchar_fd.c	\
			srcs/ft_isalpha.c
.c.o:
		${CC} ${FLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

all:		${OBJS}
		${CC} ${FLAGS} -o $@ $^
clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re