/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:25:50 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/19 21:37:43 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*instructions;

	(void)argc;
	stack = get_stack(argv);
	if (!stack)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	instructions = read_instructions();
	if (!instructions)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	sort_stack(stack, instructions);
	return (0);
}
