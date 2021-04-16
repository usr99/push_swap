/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 03:26:36 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/16 22:11:32 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_quartile_value(t_list *a, int *quartile, int size, int div)
{
	t_list	*lst;
	t_list	*tmp;
	int		mod;

	if (!(lst = ft_lstdup(a, ft_lstsize(a))))
		return (-1);
	ascending_sort(lst);
	tmp = lst;
	if (div != 4 && size < div + 1)
	{
		*quartile = *(int *)ft_lst_at(lst, size - 1)->content;
		ft_lstclear(&tmp, NULL);
		return (0);
	}
	size = (size + div - 1);
	mod = size % div;
	lst = ft_lst_at(lst, size / div - 1);
	if (mod == 0)
		*quartile = *(int *)lst->content;
	else
		*quartile = (*(int *)lst->content + *(int *)lst->next->content) / 2;
	ft_lstclear(&tmp, NULL);
	return (0);
}

int		push_sub_values(t_stack *stack, int quartile, int size)
{
	int	ra;

	ra = 0;
	while (size)
	{
		if (*(int *)(stack->a->content) <= quartile)
		{
			if (check_b(stack, *(int *)stack->a->content, ra) == -1)
				return (-1);
			if (add_instructions(stack, "pb", 1) == -1)
				return (-1);
			ra = 0;
		}
		else
		{
			if (add_instructions(stack, "ra", 1) == -1)
				return (-1);
			ra++;
			size++;
		}
		size--;
	}
	return (0);
}

int		repush_sub_values(t_stack *stack)
{
	int	pos;
	int	size;

	size = ft_lstsize(stack->b);
	while (size)
	{
		pos = find_largest(stack->b);
		if (push_a(stack, size, pos) == -1)
			return (-1);
		size--;
	}
	return (0);
}

int		check_b(t_stack *stack, int value, int ra)
{
	int	size;
	int	pos;
	int	ret;
	int	rb;

	if (ft_lstsize(stack->b) < 2)
		return (0);
	rb = 0;
	pos = find_inferior(stack->b, value);
	size = ft_lstsize(stack->b);
	if (pos <= size / 2)
	{
		ret = add_instructions(stack, "rb", pos);
		rb = pos;
	}
	else
		ret = add_instructions(stack, "rrb", size - pos);
	if (ret == -1)
		return (-1);
	if (rotate_optimization(stack, ra, rb) == -1)
		return (-1);
	return (0);
}

int		rotate_optimization(t_stack *stack, int ra, int rb)
{
	t_list	*lst;

	if (!rb)
		return (0);
	lst = ft_lstlast(stack->algorithm);
	while (lst && ft_strcmp(lst->content, "rb") == 0)
	{
		if (ra)
			optimize_ra(&lst, &ra);
		else
			lst = lst->prev;
	}
	while (lst && ft_strcmp(lst->content, "ra") == 0)
	{
		if (rb)
		{
			if (optimize_rb(lst, &rb) == -1)
				return (-1);
		}
		lst = lst->prev;
	}
	return (0);
}
