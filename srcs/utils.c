/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:01:21 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/27 02:21:51 by mamartin         ###   ########.fr       */
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
		ft_lstadd_back(&stack->algorithm, new);
		do_sort(str, &stack->a, &stack->b);
	}
	return (0);
}

int		sort_stack_size3(t_stack *stack)
{
	char	rank[4];
	int		ret;

	if (is_sorted(stack->a) == 0)
		return (0);
	ft_bzero(rank, 4);
	ret = find_smallest(stack->a);
	rank[ret] = '1';
	ret = find_largest(stack->a);
	rank[ret] = '3';
	ret = 0;
	while (rank[ret])
		ret++;
	rank[ret] = '2';
	if (ft_strncmp(rank, "312", 3) == 0)
		ret = add_instructions(stack, "ra", 1);
	else if (ft_strncmp(rank, "231", 3) == 0)
		ret = add_instructions(stack, "rra", 1);
	else
		ret = add_instructions(stack, "sa", 1);
	if (ret == -1)
		return (-1);
	if (ft_strncmp(rank, "132", 3) == 0)
		ret = add_instructions(stack, "ra", 1);
	else if (ft_strncmp(rank, "321", 3) == 0)
		ret = add_instructions(stack, "rra", 1);
	return (ret);
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

int		push_a(t_stack *stack, int size, int pos)
{
	int	ret;
	
	if (pos <= size / 2)
		ret = add_instructions(stack, "rb", pos);
	else
		ret = add_instructions(stack, "rrb", size - pos);
	if (ret == -1)
		return (-1);
	if (add_instructions(stack, "pa", 1) == -1)
		return (-1);
	return (0);
}

int		push_b(t_stack *stack, int size, int pos)
{
	int	ret;
	
	if (pos <= size / 2)
		ret = add_instructions(stack, "ra", pos);
	else
		ret = add_instructions(stack, "rra", size - pos);
	if (ret == -1)
		return (-1);
	if (add_instructions(stack, "pb", 1) == -1)
		return (-1);
	return (0);
}

int		get_lst_index(t_list *lst, int value)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (*(int *)lst->content == value)
			return (index);
		index++;
		lst = lst->next;
	}
	return (-1);
}
