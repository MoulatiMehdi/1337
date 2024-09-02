/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:49:28 by mmoulati          #+#    #+#             */
/*   Updated: 2024/06/28 22:31:23 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_combn(int pos, char str[], int start, int max)
{
	int	i;

	if (pos >= max)
	{
		write(1, str, max);
		if (str[0] != '9' - max + 1)
			write(1, ", ", 2);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		str[pos] = '0' + i;
		ft_combn(pos + 1, str, i + 1, max);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	str[11];

	str[n] = '\0';
	if (n < 1 || n > 9)
		return ;
	ft_combn(0, str, 0, n);
}
