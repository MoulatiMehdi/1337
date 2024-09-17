/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:28:13 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/18 00:47:25 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	g_n_file;

int	main(int argc, char **argv)
{
	long long	bytes;
	char		**files;
	int			i;

	g_n_file = 0;
	if (argc == 1)
		return (0);
	bytes = get_bytes(argv, argc);
	i = 0;
	if (bytes <= 0)
		return (0);
	files = get_files(argv, argc);
	if (files && files[0])
	{
		while (files[i])
		{
			if (g_n_file > 1)
				print_name(files[i]);
			if (ft_strcmp(files[i], "-") == 0)
				read_input(bytes);
			else
				read_file(files[i], bytes);
			i++;
		}
		free(files);
	}
	else
		read_input(bytes);
}
