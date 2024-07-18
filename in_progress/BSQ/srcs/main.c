/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:29:05 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/17 22:29:29 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*map;

	i = 1;
	if (argc < 2)
	{
		write(1, "Standrad inout\n", 16);
	}
	else
	{
		while (i < argc)
		{
			map = read_file(argv[i]);
			printf("%s", map);
			i++;
		}
	}
}
