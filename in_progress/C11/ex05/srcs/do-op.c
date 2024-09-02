/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:59:29 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/17 23:59:30 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_operator_index(char *str)
{
	int		i;
	char	*list;

	list = "+-*/%";
	i = 0;
	while (i < 5)
	{
		if (list[i] == str[0] && str[1] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

void	init(int (**tab)(int, int))
{
	tab[0] = sum;
	tab[1] = subtract;
	tab[2] = multiply;
	tab[3] = divide;
	tab[4] = modulo;
}

void	do_op(char *a, char *oper, char *b)
{
	int	(*tab[5])(int, int);
	int	op;
	int	nb[2];

	nb[0] = ft_atoi(a);
	nb[1] = ft_atoi(b);
	op = get_operator_index(oper);
	init(tab);
	if (op < 0)
		ft_putstr("0");
	else
	{
		if (op >= 3 && nb[1] == 0)
		{
			if (op == 3)
				ft_putstr("Stop : division by zero");
			if (op == 4)
				ft_putstr("Stop : modulo by zero");
			return ;
		}
		ft_putnbr(tab[op](nb[0], nb[1]));
	}
}
