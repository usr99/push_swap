/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:47:42 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/08 23:26:35 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **stack)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *stack;
	if (ft_lstsize(lst) < 2)
		return ;
	tmp = lst->next;
	lst->next = tmp->next;
	tmp->next = lst;
	*stack = tmp;
}

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (ft_lstsize(*b) == 0)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*lst;

	lst = *stack;
	ft_lstlast(*stack)->next = *stack;
	*stack = (*stack)->next;
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
