/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:50:10 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/17 23:50:38 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_asc;
	int	is_des;

	if (length <= 2)
		return (1);
	i = 1;
	is_asc = 1;
	is_des = 1;
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) > 0)
			is_asc = 0;
		if ((*f)(tab[i - 1], tab[i]) < 0)
			is_des = 0;
		if (is_des == 0 && is_asc == 0)
			return (0);
		i++;
	}
	return (1);
}
