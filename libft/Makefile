NAME	= libft.a
PRINTF	= ft_printf/libftprintf.a
SRCS	= ft_memset.c				\
		  	ft_bzero.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strlen.c				\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strncmp.c			\
			ft_strlcpy.c			\
			ft_strlcat.c			\
			ft_strnstr.c			\
			ft_atoi.c				\
			ft_calloc.c				\
			ft_strdup.c				\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_split.c				\
			ft_itoa.c				\
			ft_strmapi.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putendl.c			\
			ft_putnbr.c				\
			btree_apply_infix.c		\
			btree_apply_prefix.c	\
			btree_apply_suffix.c	\
			btree_create_node.c		\
			btree_insert_data.c		\
			btree_search_item.c		\
			btree_clear.c			\
			ft_lstnew.c				\
			ft_lstadd_front.c		\
			ft_lstsize.c			\
			ft_lstlast.c			\
			ft_lstadd_back.c 		\
			ft_lstdelone.c			\
			ft_lstclear.c			\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_lstdup.c				\
			ft_itoa_base.c			\
			get_next_line.c			\
			ft_free_map.c			\
			ft_clearstr.c			\
			lst_to_array.c			\
			ft_lst_at.c
OBJS	= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}
OBJ_DIR	= objs/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

${OBJ_DIR}%.o:	srcs/%.c
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:${OBJ_DIR} ${OBJS}
		${MAKE} -C ft_printf
		mv ${PRINTF} ${NAME}
		ar -rcs ${NAME} ${OBJS}

${OBJ_DIR}:	
		mkdir -p ${OBJ_DIR}

clean:
		${RM} ${OBJ_DIR}
		${MAKE} clean -C ft_printf

fclean:	clean
		${RM} ${NAME}
		${MAKE} fclean -C ft_printf
		
re: 	fclean all

.PHONY: all clean fclean re
