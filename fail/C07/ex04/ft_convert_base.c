/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:18:04 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:18:06 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_radix(char *base);
void	skip_space(char **str, int *sign);
int		ft_index(char *base, char c);
int		ft_helpers(long *big, long *tmp, int radix);

int	ft_atoi_base(char *str, char *base, int radix)
{
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	skip_space(&str, &sign);
	while (*str)
	{
		nbr = nbr * radix + ft_index(base, *str);
		str++;
	}
	return (nbr * sign);
}

char	*ft_itoa_base(int nbr, char *base, int radix)
{
	int		len;
	long	big;
	long	tmp;
	char	*p;
	int		i;

	i = 0;
	tmp = nbr;
	len = ft_helpers(&big, &tmp, radix);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	if (nbr < 0)
		p[i++] = '-';
	while (big > 0)
	{
		p[i++] = base[tmp / big];
		tmp %= big;
		big /= radix;
	}
	p[len] = '\0';
	return (p);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;
	int	radix_from;
	int	radix_to;

	radix_from = ft_radix(base_from);
	radix_to = ft_radix(base_to);
	if (radix_to < 2 || radix_from < 2)
		return (NULL);
	n = ft_atoi_base(nbr, base_from, radix_from);
	return (ft_itoa_base(n, base_to, radix_to));
}
