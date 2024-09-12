/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:10:27 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/05 11:40:38 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_default(char *str, int addr)
{
	int	i;

	i = 0;
	int_to_hex(addr, 7);
	while (str[i])
	{
		ft_putchar(' ');
		if (str[i + 1] != '\0')
			ctoh(str[i + 1]);
		else
			ctoh('\0');
		ctoh(str[i]);
		i += 2;
		if (str[i - 1] == '\0')
			break ;
	}
	while (i < 16)
	{
		ft_putstr("     ");
		i += 2;
	}
	ft_putchar('\n');
}

void	print_canonical(char *str, int addr, int repeat)
{
	int	i;

	if (repeat <= 0)
		print_default(str, addr);
	i = 0;
	while (i < repeat)
	{
		int_to_hex(addr, 8);
		ft_putstr("  ");
		str_to_hex(str, ' ');
		ft_putstr("  ");
		sanitize(str);
		ft_putchar('\n');
		i++;
	}
}

void	print_rest(char *buffer, int count, int repeat)
{
	if (count == 0)
		return ;
	buffer[count % 16] = '\0';
	if (count % 16 != 0)
		print_canonical(buffer, count - count % 16, repeat);
	int_to_hex(count, 7 + (repeat > 0));
	ft_putchar('\n');
}

int	is_printed(char *buffer, char *prev_buff, int *is_exit)
{
	if (ft_strcmp(buffer, prev_buff) == 0)
	{
		if (!*is_exit)
			ft_putstr("*\n");
		*is_exit = 1;
		return (1);
	}
	return (0);
}
