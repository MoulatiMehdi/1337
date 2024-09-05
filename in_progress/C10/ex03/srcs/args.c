/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:20:33 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/03 01:32:19 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_files(char **argv, int argc)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			count++;
		i++;
	}
	return (count);
}

char	**get_files(char **argv, int argc)
{
	char	**files;
	int		count;
	int		i;
	int		j;

	count = count_files(argv, argc);
	if (!count)
		return (0);
	files = (char **)malloc((count + 1) * sizeof(char *));
	files[count] = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			files[j++] = argv[i];
		i++;
	}
	return (files);
}

int	count_option(char **argv, int argc, char *str)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], str) == 0)
			count++;
		i++;
	}
	return (count);
}
