/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:10:03 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/18 02:10:10 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

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
