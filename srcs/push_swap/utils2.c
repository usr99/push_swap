/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:02:41 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/15 20:21:56 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_stack_size3(t_stack *stack)
{
	char	rank[4];
	int		ret;

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

void	optimize_ra(t_list **lst, int *ra)
{
	t_list	*tmp;

	tmp = (*lst)->prev;
	ft_lstdelone(*lst, &free);
	*lst = tmp;
	(*lst)->next = NULL;
	(*ra)--;
}

int		optimize_rb(t_list *lst, int *rb)
{
	free(lst->content);
	lst->content = ft_strdup("rr");
	if (!lst->content)
		return (-1);
	(*rb)--;
	return (0);
}
