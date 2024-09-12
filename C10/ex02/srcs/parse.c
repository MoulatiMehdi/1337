/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:44:54 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/26 21:22:05 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft.h"
#define UNITS "kmgtpe"

int	is_valid_unit(char *str)
{
	int		len;
	int		i;
	char	c;

	c = str[0];
	len = ft_strlen(str);
	if (len <= 0 || len > 3)
		return (len == 0);
	if (c <= 'Z' && c >= 'A')
		c += 32;
	if (len == 3 && (str[1] != 'i' || str[2] != 'B'))
		return (0);
	if (len == 2 && str[1] != 'B')
		return (0);
	if (len == 1 && c == 'b')
		return (1);
	i = 0;
	while (UNITS[i])
	{
		if (UNITS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

long long	offset(char *str)
{
	int			power;
	int			i;
	long long	size;
	char		c;

	if (!is_valid_unit(str))
		return (-1);
	c = str[0];
	if (c <= 'Z' && c >= 'A')
		c += 32;
	if (c == 'b')
		return (512);
	if (c == '\0')
		return (1);
	power = 1024;
	i = 0;
	size = 1;
	if (ft_strlen(str) == 2)
		power = 1000;
	size = power;
	while (UNITS[i] && UNITS[i++] != c)
		size *= power;
	return (size);
}

long long	parse_num(char *str)
{
	int			i;
	long long	size;
	long long	unit;

	i = 0;
	size = 0;
	if (str[0] == 0)
		return (-1);
	while (str[i] == ' ')
		i++;
	if ((str[i] < '0' || str[i] > '9') && i != 0)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		size *= 10;
		size += str[i] - '0';
		i++;
	}
	unit = offset(str + i);
	if (unit < 0)
		return (-1);
	if (size == 0 && unit != 0)
		size = 1;
	return (size * unit);
}
