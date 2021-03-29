/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:37:09 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/29 01:15:31 by mamartin         ###   ########.fr       */
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
	if (size != 1 || is_sorted(stack->a) != 0)
	{
		if (size <= 5 && size)
			ret = sort_small(stack);
		else if (size <= 500)
			ret = sort_medium(stack);
		/*else
			ret = sort_big(stack);*/
		/*if (ret != -1)
			ft_lstiter(stack->algorithm, (void (*)(void *))&ft_putendl);*/
	}
	return (ret);
}
