/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:57:09 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/03 14:47:29 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

void	ft_error(char *str, char *filename)
{
	ft_puterr(FUNC_NAME);
	write(2, ": ", 2);
	ft_puterr(filename);
	write(2, ": ", 2);
	ft_puterr(str);
	write(2, "\n", 1);
}

int	ft_errno(char *filename)
{
	ft_error(strerror(errno), filename);
	return (errno);
}
