/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:30:59 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/10 14:31:01 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned int	i;

	(void)argc;
	i = 0;
	while (argv[0][i])
		i++;
	write(1, argv[0], i);
	write(1, "\n", 1);
}
