/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:57:53 by mamartin          #+#    #+#             */
/*   Updated: 2021/04/16 21:26:48 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*read_instructions(int *ret)
{
	t_list	*instructions;
	t_list	*new;
	char	*line;

	instructions = NULL;
	while ((*ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (is_instruction(line) == -1)
		{
			*ret = -1;
			free(line);
			return (destroy_lst(&instructions));
		}
		new = ft_lstnew(line);
		if (!new)
		{
			*ret = -1;
			return (destroy_lst(&instructions));
		}
		ft_lstadd_back(&instructions, new);
	}
	free(line);
	if (*ret == -1)
		return (destroy_lst(&instructions));
	return (instructions);
}

int		is_instruction(char *str)
{
	int	length;

	length = ft_strlen(str);
	if (str[0] == 's' && length == 2)
	{
		if (ft_strchr("abs", str[1]))
			return (0);
	}
	else if (str[0] == 'p' && length == 2)
	{
		if (ft_strchr("ab", str[1]))
			return (0);
	}
	else if (str[0] == 'r' && length >= 2)
	{
		if (ft_strchr("abr", str[1]) && length == 2)
			return (0);
		else if (str[1] == 'r' && length == 3)
		{
			if (ft_strchr("abr", str[2]))
				return (0);
		}
	}
	return (-1);
}
