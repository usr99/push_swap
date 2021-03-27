/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:56:20 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/27 02:27:24 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_small(t_stack *stack)
{
	int		size;
	int		pos;
	int		ret;
	int		sz_save;

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
