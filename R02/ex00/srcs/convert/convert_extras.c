/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_extras.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:55:11 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 20:55:12 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern char	***g_numbers;

int	lookup(char *str)
{
	int	i;

	i = 0;
	while (g_numbers[i])
	{
		if (ft_strcmp(g_numbers[i][0], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	print_zero(void)
{
	int		index;
	char	*word;

	index = lookup("0");
	if (index == -1)
	{
		print_error("Dict Error");
		return ;
	}
	word = g_numbers[index][1];
	write(1, word, ft_strlen(word));
}
