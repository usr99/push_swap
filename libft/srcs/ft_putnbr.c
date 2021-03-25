/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:33:39 by mamartin          #+#    #+#             */
/*   Updated: 2021/03/23 03:30:16 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_fd('-', STDOUT_FILENO);
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, STDOUT_FILENO);
		ft_putchar_fd(nbr % 10 + '0', STDOUT_FILENO);
	}
	else
		ft_putchar_fd(nbr + '0', STDOUT_FILENO);
}
