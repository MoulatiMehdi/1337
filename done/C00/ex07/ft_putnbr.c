/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:17:02 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/06 01:07:24 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(long nb)
{
	char	c;

	c = '0' + nb % 10;
	if (nb >= 10)
		ft_print(nb / 10);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nb < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	ft_print(nbr);
}
