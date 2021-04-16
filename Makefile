CHECKER			= checker
PUSH			= push_swap
LIBFT			= libft/libft.a
OBJ_CHECK		= checker/objs
OBJ_PUSH		= push_swap/objs
FLAGS			= -Wall -Wextra -Werror

all:			${CHECKER} ${PUSH}

${CHECKER}:		${LIBFT}
				${MAKE} -C srcs/checker
				mv srcs/checker/checker .

${PUSH}:		${LIBFT}
				${MAKE} -C srcs/push_swap
				mv srcs/push_swap/push_swap .

${LIBFT}:
				${MAKE} -C libft

clean:	
				${MAKE} clean -C srcs/checker
				${MAKE} clean -C srcs/push_swap
				${MAKE} clean -C libft

fclean:			clean
				${MAKE} fclean -C libft
				rm -rf checker push_swap

re:				fclean all

.PHONY:			all clean fclean re
