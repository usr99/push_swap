NAME	= checker
LIBFT	= ../libft/libft.a
SRC		= checker.c stack.c instructions.c sort.c operations.c
OBJ		= ${SRC:.c=.o}
FLAGS	= -Wall -Wextra #-Werror

%.o:%.c
	gcc ${FLAGS} -c $< -o $@

${NAME}:${OBJ} ${LIBFT}
	gcc ${FLAGS} -o $@ ${OBJ} ${LIBFT}

${LIBFT}:
	${MAKE} bonus -C ../libft

all:${NAME}

clean:
	${MAKE} clean -C ../libft
	rm -rf ${OBJ}

fclean:clean
	${MAKE} fclean -C ../libft
	rm -rf ${NAME}

re:fclean all