/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 03:26:36 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/25 20:27:18 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_medium(t_stack *stack)
{
	int	median;

	if (get_median_value(stack->a, &median) == -1)
		return (-1);
	if (push_sub_values(stack, median) == -1)
		return (-1);
	if (insertion_sort(stack) == -1)
		return (-1);
	if (add_instructions(stack, "pa", ft_lstsize(stack->b)) == -1)
		return (-1);

	/*ft_printf("\033[31m");
	while (stack->a)
	{
		ft_printf("%d\n", *(int *)(stack->a->content));
		stack->a = stack->a->next;
	}
	ft_printf("\033[34m");
	while (stack->b)
	{
		ft_printf("%d\n", *(int *)(stack->b->content));
		stack->b = stack->b->next;
	}
	ft_printf("\033[00m");*/

	return (0);
}

int		get_median_value(t_list *a, int *median)
{
	t_list	*lst;
	int		size;
	int		i;

	i = 0;
	lst = ft_lstdup(a, ft_lstsize(a));
	if (!lst)
		return (-1);
	ascending_sort(lst);
	size = (ft_lstsize(a) + 1) / 2;
	while (++i < size)
		lst = lst->next;
	if (size % 2 == 1)
		*median = (*(int *)lst->content + *(int *)lst->next->content) / 2;
	else
		*median = *(int *)lst->content;
	ft_lstclear(&lst, NULL);
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

int		push_sub_values(t_stack *stack, int median)
{
	int		pos_topush;
	int		size;

	size = ft_lstsize(stack->a);
	while (1)
	{
		pos_topush = find_smallest(stack->a);
		if (*(int *)(ft_lst_at(stack->a, pos_topush)->content) >= median)
			break ;
		if (push_b(stack, size, pos_topush) == -1)
			return (-1);
		size--;
	}
	return (0);
}

int	insertion_sort(t_stack *stack)
{
	t_list	*lst;
	int		size;
	int		pos;

	pos = 1;
	size = ft_lstsize(stack->a);
	lst = stack->a->next;
	while (lst)
	{
		if (*(int *)(lst->content) < *(int *)(lst->prev->content))
		{
			if (pull_up(stack, lst->content, pos, size) == -1)
				return (-1);
			pos = 0;
			lst = stack->a;
		}
		pos++;
		lst = lst->next;
	}
	return (0);
}

int	pull_up(t_stack *stack, int *val, int pos_init, int size)
{
	t_list	*lst;
	int		(*f)(t_stack*, int, int, int);
	int		pos_dest;

	pos_dest = pos_init;
	lst = ft_lst_at(stack->a, pos_init);
	while (*(int *)(lst->content) >= *val && lst->prev)
	{
		pos_dest--;
		lst = lst->prev;
	}
	f = which_algo(pos_init, pos_dest, size);
	return ((*f)(stack, pos_init, pos_dest, size));
}
