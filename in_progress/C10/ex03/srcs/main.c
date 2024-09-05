/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:07:15 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/03 15:20:11 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	char	**files;
	int		count;
	char	buffer[17];

	buffer[16] = '\0';
	files = get_files(argv, argc);
	count = count_option(argv, argc, "-C");
	if (!files)
		read_input(buffer, count);
	else
	{
		ft_hexdump(files, buffer, count);
		free(files);
	}
	return (0);
}
