/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:55:20 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 20:55:21 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern char	***g_numbers;

int	handle_hundreds(char **numStr, char *buffer)
{
	if (**numStr != '0')
		if (convert_hundred(*numStr, buffer) < 0)
			return (-1);
	return (0);
}

int	handle_tens(char **numStr, char *buffer)
{
	if (**numStr == '1')
		return (convert_ten_unit(*numStr, buffer));
	if (**numStr != '0')
		if (convert_ten_unit(*numStr, buffer) < 0)
			return (-1);
	return (0);
}

int	handle_digit(char c, char *buffer)
{
	char	nbr[2];
	int		idx_dig;

	if (c != '0')
	{
		nbr[0] = c;
		nbr[1] = '\0';
		idx_dig = lookup(nbr);
		if (idx_dig == -1)
			return (-1);
		ft_strcat(buffer, g_numbers[idx_dig][1]);
	}
	return (0);
}

int	num_to_words(char *numStr, char *buffer)
{
	int	len;

	len = ft_strlen(numStr);
	if (len == 3)
	{
		if (handle_hundreds(&numStr, buffer) < 0)
			return (-1);
		len--;
		numStr++;
	}
	if (len == 2)
	{
		if (handle_tens(&numStr, buffer) < 0)
			return (-1);
	}
	if (numStr[0] != '1' && handle_digit(numStr[1], buffer) < 0)
		return (-1);
	return (0);
}
