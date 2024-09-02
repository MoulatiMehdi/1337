/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:07:15 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/29 21:38:21 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int argc, char **argv)
{
	char	**files;
	int		count;

	files = get_files(argv, argc);
	count = count_option(argv, argc, "C");
	if (!files)
		read_input(count);
	else
		read_file(files, count);
	return (0);
}
