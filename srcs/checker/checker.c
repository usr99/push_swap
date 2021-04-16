/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:25:50 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/16 20:51:17 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*instructions;
	int		ret;

	if (argc == 1)
		return (0);
	stack = get_stack(argv);
	if (!stack)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	instructions = read_instructions(&ret);
	if (ret == -1)
	{
		ft_lstclear(&stack, &free);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	sort_stack(stack, instructions);
	if (instructions)
		ft_lstclear(&instructions, &free);
	return (0);
}
