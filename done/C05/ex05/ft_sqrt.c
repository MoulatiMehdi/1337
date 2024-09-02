/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:45:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/09 12:45:35 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	double	mid;
	int		min;
	int		max;
	double	div;

	if (nb <= 0)
		return (0);
	max = nb;
	min = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		div = nb / mid;
		if (mid == div)
			return (mid);
		else if (mid > div)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return (0);
}
