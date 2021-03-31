/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 03:26:36 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/31 22:40:07 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_quartile_value(t_list *a, int *quartile, int size, int div)
{
	t_list	*lst;
	t_list	*tmp;
	int		mod;

	lst = ft_lstdup(a, ft_lstsize(a));
	if (!lst)
		return (-1);
	ascending_sort(lst);
	tmp = lst;

	if (div != 4)
	{
		if (size < div + 1)
		{
			*quartile = *(int *)ft_lst_at(lst, size - 1)->content;
			return (0);
		}
	}

	size = (size + div - 1);
	mod = size % div;
	lst = ft_lst_at(lst, size / div - 1);
	
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

int		push_sub_values(t_stack *stack, int quartile, int size, int div)
{
	int	ra;

	ra = 0;
	if (div != 4)
	{
		if (size >= div + 1)
			size /= div;
	}
	else
		size /= 4;
	while (size)
	{
		if (*(int *)(stack->a->content) <= quartile)
		{
			if (check_b(stack, *(int *)stack->a->content, ra) == -1)
				return (-1);
			if (add_instructions(stack, "pb", 1) == -1)
				return (-1);
			ra = 0;
		}
		else
		{
			if (add_instructions(stack, "ra", 1) == -1)
				return (-1);
			ra++;
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

int		check_b(t_stack *stack, int value, int ra)
{
	int	size;
	int	pos;
	int	ret;
	int	rb;

	if (ft_lstsize(stack->b) < 2)
		return (0);

	rb = 0;
	pos = find_inferior(stack->b, value);
	size = ft_lstsize(stack->b);
	
	if (pos <= size / 2)
	{
		ret = add_instructions(stack, "rb", pos);
		rb = pos;
	}
	else
		ret = add_instructions(stack, "rrb", size - pos);
	if (ret == -1)
		return (-1);

	if (rotate_optimization(stack, ra, rb) == -1)
		return (-1);
	return (0);
}

int		find_inferior(t_list *a, int value)
{
	int	pos;
	int	inf;
	int	i;

	i = 0;
	pos = 0;
	inf = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content > inf && *(int *)a->content < value)
		{
			pos = i;
			inf = *(int *)a->content;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

int		rotate_optimization(t_stack *stack, int ra, int rb)
{
	t_list	*lst;
	t_list	*tmp;

	if (!rb)
		return (0);
		
	lst = ft_lstlast(stack->algorithm);

	while (lst && ft_strcmp(lst->content, "rb") == 0)
	{
		if (ra)
		{
			tmp = lst->prev;
			ft_lstdelone(lst, &free);
			lst = tmp;
			lst->next = NULL;
			ra--;
		}
		else
			lst = lst->prev;
	}
	while (lst && ft_strcmp(lst->content, "ra") == 0)
	{
		if (rb)
		{
			free(lst->content);
			lst->content = ft_strdup("rr");
			if (!lst->content)
				return (-1);
			rb--;
		}
		lst = lst->prev;
	}
	return (0);
}
