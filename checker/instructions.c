/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:57:53 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/08 18:42:20 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*read_instructions(void)
{
	t_list	*instructions;
	t_list	*new;
	char	*line;
	int		ret;

	instructions = NULL;
	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (is_instruction(line) == -1)
			return (destroy_lst(&instructions));
		new = ft_lstnew(line);
		if (!new)
			return (destroy_lst(&instructions));
		ft_lstadd_back(&instructions, new);
	}
	if (ret == -1)
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
