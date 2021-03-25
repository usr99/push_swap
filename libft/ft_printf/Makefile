NAME	= libftprintf.a
SRC		= ft_printf.c srcs/ft_flags.c srcs/ft_print_diux.c \
			srcs/ft_print_utils.c srcs/ft_print_csp.c
OBJ		= ${SRC:.c=.o}
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJ}
		ar -rcs ${NAME} ${OBJ}

all:	${NAME}

clean:
		rm -rf ${OBJ}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all

.PHONY: all clean fclean re
