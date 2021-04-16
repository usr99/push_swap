/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:47:42 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/16 01:02:55 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_list **stack)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *stack;
	if (ft_lstsize(lst) < 2)
		return ;
	tmp = lst->next;
	lst->next = tmp->next;
	lst->next->prev = lst;
	lst->prev = tmp;
	tmp->next = lst;
	tmp->prev = NULL;
	*stack = tmp;
}

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (ft_lstsize(*b) == 0)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	tmp->prev = NULL;
	if (*a)
		tmp->next->prev = tmp;
	*a = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*lst;
	t_list	*last;

	lst = *stack;
	if (ft_lstsize(lst) < 2)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	last->next->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	lst->next = NULL;
}

void	rev_rotate(t_list **stack)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *stack;
	if (ft_lstsize(lst) < 2)
		return ;
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
	}
	tmp->next = NULL;
	lst->next = *stack;
	lst->prev = NULL;
	lst->next->prev = lst;
	*stack = lst;
}

int		is_sorted(t_list *a)
{
	int	*tmp;
	int	*val;

	tmp = NULL;
	while (a)
	{
		val = a->content;
		if (tmp)
		{
			if (*tmp > *val)
				return (-1);
		}
		tmp = val;
		a = a->next;
	}
	return (0);
}
