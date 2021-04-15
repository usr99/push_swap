/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:25:50 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/15 16:15:19 by mamartin         ###   ########.fr       */
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
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	sort_stack(stack, instructions);
	return (0);
}
