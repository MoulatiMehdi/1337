/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:28:13 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/28 00:22:31 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int argc, char **argv)
{
	long long	bytes;
	char		**files;
	int			i;

	if (argc == 1)
		return (0);
	bytes = get_bytes(argv, argc);
	i = 0;
	if (bytes < 0)
		return (1);
	files = get_files(argv, argc);
	if (files && files[0])
	{
		while (files[i])
		{
			read_file(files[i], bytes);
			i++;
		}
		free(files);
	}
	else
		read_input(bytes);
}
