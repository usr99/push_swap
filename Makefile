CHECKER			= checker
PUSH			= push_swap
LIBFT			= libft/libft.a
SRC_CHECK		= checker.c			\
					stack.c			\
					file.c			\
					instructions.c	\
					sort.c			\
					operations.c
SRC_PUSH		= push_swap.c		\
					sort_medium.c	\
					utils.c			\
					utils2.c		\
					stack.c			\
					file.c			\
					sort.c			\
					operations.c
OBJ_CHECK		= ${addprefix ${OBJ_DIR}, ${SRC_CHECK:.c=.o}} 
OBJ_PUSH		= ${addprefix ${OBJ_DIR}, ${SRC_PUSH:.c=.o}} 
OBJ_DIR			= objs/
FLAGS			= -Wall -Wextra -Werror

${OBJ_DIR}%.o:	srcs/%.c
				gcc ${FLAGS} -c $< -o $@

all:			${CHECKER} ${PUSH}

${CHECKER}:		${OBJ_DIR} ${OBJ_CHECK} ${LIBFT}
				gcc ${FLAGS} -o $@ ${OBJ_CHECK} ${LIBFT}

${PUSH}:		${OBJ_DIR} ${OBJ_PUSH} ${LIBFT}
				gcc ${FLAGS} -o $@ ${OBJ_PUSH} ${LIBFT}

${LIBFT}:
				${MAKE} -C libft

${OBJ_DIR}:	
				mkdir -p ${OBJ_DIR}

clean:	
				rm -rf ${OBJ_DIR}
				${MAKE} clean -C libft

fclean:			clean
				rm -rf ${CHECKER}
				rm -rf ${PUSH}
				${MAKE} fclean -C libft

re:				fclean all

.PHONY:			all clean fclean re
