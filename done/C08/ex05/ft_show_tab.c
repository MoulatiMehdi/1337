/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:35:18 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:35:19 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
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
	ft_putchar('\n');
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	if (par == NULL || par[0].str == NULL)
		return ;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}
