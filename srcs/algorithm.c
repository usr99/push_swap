/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:59:57 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/25 19:24:12 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	(*which_algo(int init, int dest, int size))(t_stack *, int, int, int)
{
	int	cost[4];
	int	best;
	int	index;
	int	i;

	i = 1;
	index = 1;
	cost[0] = (init - dest) * 2 + dest * 2 + 2;
	cost[1] = (init - dest) * 3 + dest * 2 - 2;
	cost[2] = (size - init - 1) * 2 + dest * 2 + 3;
	cost[3] = (size - init + dest) * 3 - 2;
	best = cost[0];
	while (i < 4)
	{
		if (best > cost[i])
		{
			index = i;
			best = cost[i];
		}
		i++;
	}
	if (index == 0)
		return (&algo_push);
	else if (index == 1)
		return (&algo_swap);
	else if (index == 2)
		return (&algo_rev_push);
	else	
		return (&algo_rev_swap);
}

int	algo_push(t_stack *stack, int init, int dest, int size)
{
	(void)size;
	if (add_instructions(stack, "ra", init) == -1)
		return (-1);
	if (add_instructions(stack, "pb", 1) == -1)
		return (-1);
	if (add_instructions(stack, "rra", dest) == -1)
		return (-1);
	if (add_instructions(stack, "pa", 1) == -1)
		return (-1);
	if (add_instructions(stack, "rra", dest) == -1)
		return (-1);
	return (0);
}

int	algo_rev_push(t_stack *stack, int init, int dest, int size)
{
	if (add_instructions(stack, "rra", size - init) == -1)
		return (-1);
	if (add_instructions(stack, "pb", 1) == -1)
		return (-1);
	if (add_instructions(stack, "ra", dest + (size - init - 1)) == -1)
		return (-1);
	if (add_instructions(stack, "pa", 1) == -1)
		return (-1);
	if (add_instructions(stack, "rra", dest) == -1)
		return (-1);
	return (0);
}

int	algo_swap(t_stack *stack, int init, int dest, int size)
{
	int	i;

	(void)size;
	i = init - dest;
	if (add_instructions(stack, "ra", init - 1) == -1)
		return (-1);
	while (i--)
	{
		if (add_instructions(stack, "sa", 1) == -1)
			return (-1);
		if (i != 0)
		{
			if (add_instructions(stack, "rra", 1) == -1)
				return (-1);
		}
	}
	if (add_instructions(stack, "rra", dest - 1) == -1)
		return (-1);
	return (0);
}

int	algo_rev_swap(t_stack *stack, int init, int dest, int size)
{
	int	i;

	i = dest + size - init - 1;
	if (add_instructions(stack, "rra", size - init) == -1)
		return (-1);
	while (i--)
	{
		if (add_instructions(stack, "sa", 1) == -1)
			return (-1);	
		if (add_instructions(stack, "ra", 1) == -1)
			return (-1);
	}
	if (add_instructions(stack, "rra", dest) == -1)
		return (-1);
	return (0);
}
