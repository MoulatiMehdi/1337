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
int main(int argc, char **argv)
{
	int i;
	char *text;
	if (argc < 2)
	{
		text = read_input();
		solve(text);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			text = read_file(argv[i]);
			solve(text);
			if (i < argc - 1)
				ft_putstr("\n");
			i++;
		}
	}
}
