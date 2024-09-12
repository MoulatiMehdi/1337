/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:17:53 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:17:55 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int			*p;
	int			i;
	long long	size;

	size = max - min;
	if (size <= 0)
		return (NULL);
	i = 0;
	p = (int *)malloc(sizeof(int) * (size));
	if (p != NULL)
	{
		while (min + i < max)
		{
			p[i] = min + i;
			i++;
		}
	}
	return (p);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == NULL)
		return (-1);
	return (max - min);
}
