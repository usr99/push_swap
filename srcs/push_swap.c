/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:37:09 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/15 15:58:53 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;
	int		ret;

	(void)ac;
	stack.a = get_stack(av);
	stack.b = NULL;
	stack.algorithm = NULL;
	if (!stack.a)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	ret = push_swap(&stack);
	ft_lstclear(&stack.a, &free);
	ft_lstclear(&stack.b, &free);
	ft_lstclear(&stack.algorithm, &free);
	return (ret);
}

int	push_swap(t_stack *stack)
{
	int	size;
	int	ret;

	size = ft_lstsize(stack->a);
	if (size != 1 && is_sorted(stack->a) != 0)
	{
		if (size <= 5 && size)
			ret = sort_small(stack);
		else if (size <= 100)
			ret = sort_medium(stack);
		else
			ret = sort_big(stack);
		if (ret != -1)
			ft_lstiter(stack->algorithm, (void (*)(void *))&ft_putendl);
	}
	return (ret);
}

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
	if (is_sorted(stack->a) == -1)
	{
		if (sort_stack_size3(stack) == -1)
			return (-1);
	}
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
		if (push_sub_values(stack, quartile, size / 4) == -1)
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
		if (size >= 7 + 1)
			size /= 7;
		if (push_sub_values(stack, quartile, size) == -1)
			return (-1);
		size = ft_lstsize(stack->a);
	}
	if (repush_sub_values(stack) == -1)
		return (-1);
	return (0);
}
