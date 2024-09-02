/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:17:02 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/06 01:07:24 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_str_in_base(char *str, char *base)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (base[j])
		{
			if (base[j] == str[i])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}

int	is_invalid_base_char(char c)
{
	return (c < 33 || c > 126 || c == '+' || c == '-');
}

int	get_radix(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (is_invalid_base_char(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
			if (base[j++] == base[i])
				return (0);
		i++;
	}
	return (i);
}

void	skip_space(char **str, int *sign)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		*str += 1;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign *= -1;
		*str += 1;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	radix;
	long			nbr;
	int				sign;
	int				rev[128];
	int				i;

	sign = 1;
	i = 0;
	nbr = 0;
	skip_space(&str, &sign);
	radix = get_radix(base);
	if (radix < 2 || !is_str_in_base(str, base))
		return (0);
	while (base[i])
	{
		rev[(int)base[i]] = i;
		i++;
	}
	while (*str)
	{
		nbr = nbr * radix + rev[(int)*str];
		str++;
	}
	return (sign * nbr);
}
