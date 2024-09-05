/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:01:56 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/07 22:02:24 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(long nb, char *base, unsigned int radix)
{
	if (nb >= radix)
		ft_print(nb / radix, base, radix);
	write(1, base + nb % radix, 1);
}

int	is_valid_base_char(char c)
{
	return (c < 33 || c > 126 || c == '+' || c == '-');
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	radix;
	unsigned int	j;
	long			nbr;

	nbr = nb;
	radix = 0;
	while (base[radix])
	{
		if (is_valid_base_char(base[radix]))
			return ;
		j = radix;
		while (base[++j])
			if (base[j] == base[radix])
				return ;
		radix++;
	}
	if (radix < 2)
		return ;
	if (nb < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	ft_print(nbr, base, radix);
}
