/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:19:04 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/15 14:11:05 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*get_stack_from_file(char **argv)
{
	t_list	*stack;
	int		fd;

	fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		return (NULL);
	stack = read_file(fd);
	close(fd);
	return (stack);
}

t_list	*read_file(int fd)
{
	t_list	*stack;
	t_list	*new;
	t_list	*tmp;
	char	*line;
	int		*nb;

	new = NULL;
	stack = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_integer(line, &nb) == -1 || is_duplicate(stack, *nb) != -1)
			return (destroy_lst(&stack));
		tmp = new;
		new = ft_lstnew(nb);
		if (!new)
			return (destroy_lst(&stack));
		ft_lstadd_back(&stack, new);
		new->prev = tmp;
		free(line);
	}
	free(line);
	return (stack);
}
