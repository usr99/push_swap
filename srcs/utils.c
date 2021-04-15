/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:01:21 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/15 16:03:22 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_instructions(t_stack *stack, char *instruction, int x)
{
	t_list	*new;
	char	*str;

	while (x-- > 0)
	{
		str = ft_strdup(instruction);
		if (!str)
			return (-1);
		new = ft_lstnew(str);
		if (!new)
			return (-1);
		if (!stack->algorithm)
			new->prev = NULL;
		else
			new->prev = ft_lstlast(stack->algorithm);
		ft_lstadd_back(&stack->algorithm, new);
		do_sort(str, &stack->a, &stack->b);
	}
	return (0);
}

void	ascending_sort(t_list *lst)
{
	t_list	*save;
	int		*tmp;

	save = lst;
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
		{
			tmp = lst->content;
			lst->content = lst->next->content;
			lst->next->content = tmp;
			lst = save;
		}
		else
			lst = lst->next;
	}
}

int		find_smallest(t_list *a)
{
	int	tmp;
	int	pos;
	int	i;

	i = 0;
	tmp = 0;
	while (a)
	{
		if (tmp > *(int *)(a->content) || i == 0)
		{
			tmp = *(int *)(a->content);
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

int		find_largest(t_list *a)
{
	int	tmp;
	int	pos;
	int	i;

	i = 0;
	tmp = 0;
	while (a)
	{
		if (tmp < *(int *)(a->content) || i == 0)
		{
			tmp = *(int *)(a->content);
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

int		find_inferior(t_list *a, int value)
{
	int	pos;
	int	inf;
	int	i;

	i = 0;
	pos = 0;
	inf = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content > inf && *(int *)a->content < value)
		{
			pos = i;
			inf = *(int *)a->content;
		}
		i++;
		a = a->next;
	}
	return (pos);
}
