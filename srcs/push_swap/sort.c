/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:41:40 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/20 20:58:11 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_stack(t_list *a, t_list *instructions)
{
	t_list	*b;

	b = NULL;
	while (instructions)
	{
		do_sort(instructions->content, &a, &b);
		instructions = instructions->next;
	}
	if (b != NULL || is_sorted(a) == -1)
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	else
		ft_putstr_fd("OK\n", STDOUT_FILENO);
}

void	do_sort(char *instruction, t_list **a, t_list **b)
{
	if (instruction[0] == 's')
		do_swap(instruction[1], a, b);
	else if (instruction[0] == 'p')
	{
		if (instruction[1] == 'a')
			push(a, b);
		else
			push(b, a);
	}
	else if (ft_strlen(instruction) == 2)
		do_rotate(instruction[1], a, b);
	else
		do_rev_rotate(instruction[2], a, b);
}

void	do_swap(char stack, t_list **a, t_list **b)
{
	if (stack == 'a')
		swap(a);
	else if (stack == 'b')
		swap(b);
	else if (stack == 's')
	{
		swap(a);
		swap(b);
	}
}

void	do_rotate(char stack, t_list **a, t_list **b)
{
	if (stack == 'a')
		rotate(a);
	else if (stack == 'b')
		rotate(b);
	else if (stack == 'r')
	{
		rotate(a);
		rotate(b);
	}
}

void	do_rev_rotate(char stack, t_list **a, t_list **b)
{
	if (stack == 'a')
		rev_rotate(a);
	else if (stack == 'b')
		rev_rotate(b);
	else if (stack == 'r')
	{
		rev_rotate(a);
		rev_rotate(b);
	}
}
