/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:57:07 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/28 00:26:56 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_puterr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
}

/*
 * Print message to the Standard Error
 *
 **/
void	error(char *filename, int errnum)
{
	ft_puterr("ft_tail: ");
	ft_puterr(basename(filename));
	ft_puterr(": ");
	ft_puterr(strerror(errnum));
	ft_puterr("\n");
}
