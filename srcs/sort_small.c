/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:56:20 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/31 22:27:23 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_small(t_stack *stack)
{
	int	size;
	int	pos;
	int	ret;
	int	sz_save;

	if (is_sorted(stack->a) == 0)
		return (0);
	size = ft_lstsize(stack->a);
	sz_save = size;
	while (size > 3)
	{
		pos = find_smallest(stack->a);
		if (push_b(stack, size, pos) == -1)
			return (-1);
		size--;
	}
	if (sort_stack_size3(stack) == -1)
		return (-1);
	ret = add_instructions(stack, "pa", sz_save - 3);
	return (ret);
}

int		sort_medium(t_stack *stack)
{
	int	quartile;
	int	size;

	size = ft_lstsize(stack->a);
	while (size > 3)
	{
		if (get_quartile_value(stack->a, &quartile, size, 4) == -1)
			return (-1);
		if (push_sub_values(stack, quartile, size, 4) == -1)
			return (-1);
		size = ft_lstsize(stack->a);
	}
	if (sort_small(stack) == -1)
		return (-1);
	if (repush_sub_values(stack) == -1)
		return (-1);
	return (0);
}

int		sort_big(t_stack *stack)
{
	int	quartile;
	int	size;

	size = ft_lstsize(stack->a);
	while (size)
	{
		if (get_quartile_value(stack->a, &quartile, size, 7) == -1)
			return (-1);
		if (push_sub_values(stack, quartile, size, 7) == -1)
			return (-1);
		size = ft_lstsize(stack->a);
	}
	if (repush_sub_values(stack) == -1)
		return (-1);
	return (0);
}
