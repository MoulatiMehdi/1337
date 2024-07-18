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
#include <stdlib.h>

void	fill_square(struct s_grid map, int max_i, int max_j, int max_of_s)
{
	int	i;
	int	j;

	i = max_i;
	j = max_j;
	while (i > max_i - max_of_s)
	{
		j = max_j;
		while (j > max_j - max_of_s)
		{
			map.data[i][j] = map.full;
			j--;
		}
		i--;
	}
}

void	find_max_square_size(int **mtrx, int height, int width,
		struct s_grid map)
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
	find_max_square_size(mtrx, map.height, map.width, map);
}

struct s_grid	init_map(char *sets, int height, int width)
{
	struct s_grid	grid;

	grid.height = height;
	grid.width = width;
	grid.data = create_strs(height, width);
	grid.empty = sets[0];
	grid.ostacle = sets[1];
	grid.full = sets[2];
	return (grid);
}

void	copy_data(struct s_grid grid, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid.height)
	{
		j = 0;
		while (j < grid.width)
		{
			grid.data[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

void	print_data(struct s_grid map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			write(1, &map.data[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
