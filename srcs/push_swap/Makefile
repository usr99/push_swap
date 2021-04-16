NAME			= push_swap
LIBFT			= ../../libft/libft.a
SRC				= push_swap.c		\
					insertion_sort.c\
					utils.c			\
					utils2.c		\
					stack.c			\
					sort.c			\
					operations.c
OBJ				= ${addprefix ${OBJ_DIR}, ${SRC:.c=.o}} 
OBJ_DIR			= objs/
FLAGS			= -Wall -Wextra -Werror

${OBJ_DIR}%.o:	%.c
				gcc ${FLAGS} -c $< -o $@

${NAME}:		${OBJ_DIR} ${OBJ} ${LIBFT}
				gcc ${FLAGS} -o $@ ${OBJ} ${LIBFT}

all:			${NAME}

${LIBFT}:
				${MAKE} -C ../../libft

${OBJ_DIR}:	
				mkdir -p ${OBJ_DIR}

clean:	
				${MAKE} clean -C ../../libft
				rm -rf ${OBJ_DIR}

fclean:			clean
				${MAKE} fclean -C ../../libft
				rm -rf ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
