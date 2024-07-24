/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:30:42 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/18 16:30:52 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	fill_square(struct s_grid map, int y, int x, int length)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (i > y - length)
	{
		j = x;
		while (j > x - length)
		{
			map.data[i][j] = map.full;
			j--;
		}
		i--;
	}
}

void	max_size_square(int **mtrx, int height, int width, struct s_grid map)
{
	int	max[3];
	int	i;
	int	j;

	i = 0;
	max[2] = mtrx[0][0];
	max[0] = 0;
	max[1] = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (max[2] < mtrx[i][j])
			{
				max[2] = mtrx[i][j];
				max[0] = i;
				max[1] = j;
			}
			j++;
		}
		i++;
	}
	fill_square(map, max[0], max[1], max[2]);
}

void	find_max_square(struct s_grid map)
{
	int	i;
	int	j;
	int	**mtrx;

	mtrx = create_matrix(map.height, map.width);
	init_matrix(mtrx, map);
	i = 1;
	while (i < map.height)
	{
		j = 1;
		while (j < map.width)
		{
			if (map.data[i][j] == map.empty)
				mtrx[i][j] = min(mtrx[i][j - 1], mtrx[i - 1][j], mtrx[i - 1][j
						- 1]) + 1;
			else
				mtrx[i][j] = 0;
			j++;
		}
		i++;
	}
	max_size_square(mtrx, map.height, map.width, map);
	free_grid(&mtrx);
}
