/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:52:11 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/18 00:45:24 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	print_name(char *filename)
{
	if (strcmp("-", filename) == 0)
		filename = "standard input";
	ft_putstr(L_ARROW);
	ft_putstr(filename);
	ft_putstr(R_ARROW);
	ft_putstr("\n");
}
