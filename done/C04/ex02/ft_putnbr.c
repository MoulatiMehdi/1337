/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:17:02 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/07 18:48:18 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long	tmp;
	int			ndigit;

	tmp = nb;
	ndigit = 1;
	if (nb < 0)
	{
		tmp *= -1;
		ft_putchar('-');
	}
	while (tmp / ndigit > 9)
		ndigit *= 10;
	while (ndigit > 0)
	{
		ft_putchar(tmp / ndigit + '0');
		tmp %= ndigit;
		ndigit /= 10;
	}
}
