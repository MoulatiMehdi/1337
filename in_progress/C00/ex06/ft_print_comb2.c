/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:49:28 by mmoulati          #+#    #+#             */
/*   Updated: 2024/06/28 22:35:04 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putn(int n)
{
	char	k1;
	char	k2;

	k1 = '0' + n / 10;
	k2 = '0' + n % 10;
	write(1, &k1, 1);
	write(1, &k2, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putn(i);
			write(1, " ", 1);
			ft_putn(j);
			if (j == 99 && i == j - 1)
				return ;
			write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
