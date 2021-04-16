CHECKER			= checker
PUSH			= push_swap
LIBFT			= libft/libft.a
FLAGS			= -Wall -Wextra -Werror

all:			${CHECKER} ${PUSH}

${CHECKER}:		${LIBFT}
				${MAKE} -C srcs/checker
				ln -s srcs/checker/checker .

${PUSH}:		${LIBFT}
				${MAKE} -C srcs/push_swap
				ln -s srcs/push_swap/push_swap .

${LIBFT}:
				${MAKE} -C libft

clean:	
				${MAKE} clean -C srcs/checker
				${MAKE} clean -C srcs/push_swap
				${MAKE} clean -C libft

fclean:			clean
				${MAKE} fclean -C libft
				${MAKE} fclean -C srcs/checker
				${MAKE} fclean -C srcs/push_swap
				rm -rf checker push_swap

re:				fclean all

.PHONY:			all clean fclean re
