/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:23:08 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/29 20:02:10 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft.h"

#define HEX "0123456789abcdef"

/*
 * Print a character to the standard output
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
void	int_to_hex(int addr)
{
	int	power;

	power = 16777216;
	while (power > 0)
	{
		ft_putchar(HEX[addr / 16]);
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
		ctoh(str[i]);
		i++;
	}
	while (i < 16)
	{
		ft_putchar(sep);
		ft_putstr("  ");
		i++;
	}
}
