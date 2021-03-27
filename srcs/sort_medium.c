/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 03:26:36 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/27 02:47:49 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_medium(t_stack *stack)
{
	int	quartile;
	int	size;

	size = ft_lstsize(stack->a);
	while (size > 5)
	{
		if (get_quartile_value(stack->a, &quartile) == -1)
			return (-1);
		if (push_sub_values(stack, quartile, size) == -1)
			return (-1);
		size = ft_lstsize(stack->a);
	}
	if (sort_small(stack) == -1)
		return (-1);
	if (repush_sub_values(stack) == -1)
		return (-1);

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

int		get_quartile_value(t_list *a, int *quartile)
{
	t_list	*lst;
	t_list	*tmp;
	int		size;
	int		mod;

	lst = ft_lstdup(a, ft_lstsize(a));
	if (!lst)
		return (-1);
	ascending_sort(lst);
	tmp = lst;
	size = (ft_lstsize(a) + 3);
	mod = size % 4;
	lst = ft_lst_at(lst, size / 4 - 1);
	if (mod == 0)
		*quartile = *(int *)lst->content;
	else if (mod == 1)
		*quartile = ((*(int *)lst->content) * 3 + *(int *)lst->next->content) / 4;
	else if (mod == 2)
		*quartile = (*(int *)lst->content + *(int *)lst->next->content) / 2;
	else if (mod == 3)
		*quartile = (*(int *)lst->content + (*(int *)lst->next->content) * 3) / 4;
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
	t_list	*lst;
	int		pos[2];

	//ft_printf("=== %d === %d ===\n", i, size % 4);
	while (size > 5)
	{
		pos[0] = 0;
		lst = stack->a;
		while (lst && *(int *)lst->content >= quartile)
		{
			pos[0]++;
			lst = lst->next;
		}
		if (pos[0] == size)
			break ;
		pos[1] = size - 1;
		lst = ft_lstlast(stack->a);
		while (lst && *(int *)lst->content >= quartile)
		{
			pos[1]--;
			lst = lst->prev;
		}
		if (size - pos[1] < pos[0])
			pos[0] = pos[1];
		//ft_printf("%d %d\n", pos[0], pos[1]);
		//ft_printf("quintile = %d, on push %d | %d\n", quartile, *(int *)(ft_lst_at(stack->a, pos[0])->content));
		if (push_b(stack, size, pos[0]) == -1)
			return (-1);
		size--;
	}
	return (0);

	/*
	t_list	*lst;
	int		pos[2];
	int		i;

	i = size / 5;
	//ft_printf("=== %d ===\n", i);
	while (i--)
	{
		pos[0] = 0;
		lst = stack->a;
		while (lst && *(int *)lst->content >= quartile)
		{
			pos[0]++;
			lst = lst->next;
		}
		pos[1] = size - 1;
		lst = ft_lstlast(stack->a);
		while (lst && *(int *)lst->content >= quartile)
		{
			pos[1]--;
			lst = lst->prev;
		}
		if (size - pos[1] < pos[0])
			pos[0] = pos[1];
		//ft_printf("quintile = %d, on push %d\n", quartile, *(int *)(ft_lst_at(stack->a, pos[0])->content));
		if (push_b(stack, size, pos[0]) == -1)
			return (-1);		
		size--;
	}
	*/

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
