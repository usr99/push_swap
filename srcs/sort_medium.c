/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 03:26:36 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/29 17:00:40 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_medium(t_stack *stack)
{
	int	quartile;
	int	size;

	size = ft_lstsize(stack->a);
	while (size > 3)
	{
		if (get_quartile_value(stack->a, &quartile, size) == -1)
			return (-1);
		if (push_sub_values(stack, quartile, size) == -1)
			return (-1);
		size = ft_lstsize(stack->a);
	}
	ft_printf("%d\n", ft_lstsize(stack->algorithm));
	if (sort_small(stack) == -1)
		return (-1);
	if (repush_sub_values(stack) == -1)
		return (-1);
	ft_printf("%d\n", ft_lstsize(stack->algorithm));

	/*ft_printf("\033[34m");
	while (stack->a)
	{
		ft_printf("%d\n", *(int *)(stack->a->content));
		stack->a = stack->a->next;
	}
	ft_printf("\033[31m");
	while (stack->b)
	{
		ft_printf("%d\n", *(int *)(stack->b->content));
		stack->b = stack->b->next;
	}
	ft_printf("\033[00m");*/

	return (0);
}

int		get_quartile_value(t_list *a, int *quartile, int size)
{
	t_list	*lst;
	t_list	*tmp;
	int		mod;

	lst = ft_lstdup(a, ft_lstsize(a));
	if (!lst)
		return (-1);
	ascending_sort(lst);
	tmp = lst;

	size = (size + 4 - 1);
	mod = size % 4;
	lst = ft_lst_at(lst, size / 4 - 1);
	
	if (mod == 0)
		*quartile = *(int *)lst->content;
	else
		*quartile = (*(int *)lst->content + *(int *)lst->next->content) / 2;
		
	ft_lstclear(&tmp, NULL);
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

int		push_sub_values(t_stack *stack, int quartile, int size)
{
	size /= 4;
	while (size)
	{
		if (*(int *)(stack->a->content) <= quartile)
		{
			if (add_instructions(stack, "pb", 1) == -1)
				return (-1);
		}
		else
		{
			if (add_instructions(stack, "ra", 1) == -1)
				return (-1);
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

int		check_b_order(t_stack *stack, int value)
{

}
