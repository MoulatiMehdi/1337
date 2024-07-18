/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:45:57 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/09 12:45:58 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_reach(int x, int y, int x1, int y1)
{
	return (x == x1 || y == y1 || (x - x1) == (y - y1) || (x - x1) == (y1 - y));
}

int	ft_is_valid_queen_place(char *queens, int col, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < col)
	{
		j = queens[i] - '0';
		if (ft_is_reach(i, j, col, row))
			return (0);
		i++;
	}
	return (1);
}

int	ft_place_queens(char *queens, int level)
{
	int	count;
	int	j;

	if (level >= 10)
	{
		write(1, queens, 10);
		write(1, "\n", 1);
		return (1);
	}
	j = 0;
	count = 0;
	while (j < 10)
	{
		if (ft_is_valid_queen_place(queens, level, j))
		{
			queens[level] = '0' + j;
			count += ft_place_queens(queens, level + 1);
		}
		j++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	queens[10];

	return (ft_place_queens(queens, 0));
}
