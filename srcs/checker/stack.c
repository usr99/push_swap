/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:58:25 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/16 03:03:09 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*get_stack(char **argv)
{
	t_list	*stack;
	t_list	*new;
	t_list	*tmp;
	int		*nb;
	int		i;

	i = 1;
	new = NULL;
	stack = NULL;
	while (argv[i])
	{
		if (is_integer(argv[i], &nb) == -1 || is_duplicate(stack, *nb) != -1)
			return (destroy_lst(&stack));
		tmp = new;
		new = ft_lstnew(nb);
		if (!new)
			return (destroy_lst(&stack));
		ft_lstadd_back(&stack, new);
		new->prev = tmp;
		i++;
	}
	return (stack);
}

int		is_integer(char *str, int **nb)
{
	long	lnb;
	int		i;

	i = 0;
	if (str[0] == '-' && ft_strlen(str) == 1)
		return (-1);
	if (str[0] == '-')
		i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	lnb = ft_atoi(str);
	if (lnb < INT_MIN || lnb > INT_MAX)
		return (-1);
	*nb = malloc(sizeof(int));
	if (*nb == NULL)
		return (-1);
	**nb = lnb;
	return (0);
}

int		is_duplicate(t_list *stack, int value)
{
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (0);
		stack = stack->next;
	}
	return (-1);
}

void	*destroy_lst(t_list **lst)
{
	ft_lstclear(lst, &free);
	return (NULL);
}
