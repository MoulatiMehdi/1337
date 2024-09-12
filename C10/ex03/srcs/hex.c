/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:23:08 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/03 22:42:45 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

#define HEX "0123456789abcdef"

/*
 * Print the hexadecimal convertion of the character
 */
void	ctoh(unsigned char c)
{
	ft_putchar(HEX[c / 16]);
	ft_putchar(HEX[c % 16]);
}

/*
 * Print the hexadecimal convertion of the integer
 */
void	int_to_hex(unsigned int addr, int bytes)
{
	int	power;

	power = 1;
	while (bytes - 1 > 0)
	{
		power *= 16;
		bytes--;
	}
	while (power > 0)
	{
		ft_putchar(HEX[addr / power]);
		addr %= power;
		power /= 16;
	}
}

void	str_to_hex(char *str, char sep)
{
	int	i;

	i = 1;
	ctoh(str[0]);
	while (str[i])
	{
		ft_putchar(sep);
		if (i % 8 == 0)
			ft_putchar(sep);
		ctoh(str[i]);
		i++;
	}
	while (i < 16)
	{
		ft_putchar(sep);
		if (i % 8 == 0)
			ft_putchar(sep);
		ft_putstr("  ");
		i++;
	}
}

void	sanitize(char *str)
{
	int		i;
	char	c;

	i = 0;
	ft_putchar('|');
	while (str[i])
	{
		c = str[i];
		if (c < ' ' || c > 126)
			c = '.';
		ft_putchar(c);
		i++;
	}
	ft_putchar('|');
}
