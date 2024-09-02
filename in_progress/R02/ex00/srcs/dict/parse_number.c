/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:55:37 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 20:55:39 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern char	***g_numbers;

char	*create_number(char *buffer, int position)
{
	char	*number;

	number = malloc(sizeof(char) * (position + 1));
	if (number != NULL)
		ft_strcpy(number, buffer);
	return (number);
}

int	parse_extract_number(char *str, char *buffer)
{
	int	position;

	position = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		if (*str == '0' && position == 0)
		{
			str++;
			continue ;
		}
		buffer[position] = *str;
		position++;
		str++;
	}
	return (position);
}

char	*parse_number(char *str)
{
	char	buffer[1024];
	int		position;

	position = 0;
	if (*str == '\0')
		return (NULL);
	position = parse_extract_number(str, buffer);
	if (position == 0)
	{
		buffer[0] = '0';
		position++;
	}
	buffer[position] = '\0';
	return (create_number(buffer, position));
}
