/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 04:13:21 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/23 16:18:51 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**lst_to_array(t_list *lst)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (lst)
	{
		array[i] = (char *)lst->content;
		lst = lst->next;
		i++;
	}
	return (array);
}
