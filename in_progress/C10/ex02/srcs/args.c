/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:26:23 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/28 00:47:58 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

static int	count_files(char **argv, int argc)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			i++;
		else
			count++;
		i++;
	}
	return (count);
}

void	invalid_bytes(char *str)
{
	ft_puterr("ft_tail : invalid number of bytes: ‘");
	ft_puterr(str);
	ft_puterr("’\n");
}

long long	get_bytes(char **argv, int argc)
{
	long long	bytes;
	int			i;

	i = 1;
	bytes = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-c") == 0)
		{
			i++;
			if (i >= argc)
			{
				ft_puterr("ft_tail : option requires an argument -- 'c'\n");
				return (-1);
			}
			bytes = parse_num(argv[i]);
			if (bytes < 0)
			{
				invalid_bytes(argv[i]);
				return (-1);
			}
		}
		i++;
	}
	return (bytes);
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
		if (argv[i][0] == '-')
			i++;
		else
			files[j++] = argv[i];
		i++;
	}
	return (files);
}
