/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:18:10 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:18:12 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_radix(char *base)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (base[i])
	{
		c = base[i];
		if (c == '+' || c == '-' || c < 33 || c > 126)
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

int	ft_helpers(long *big, long *tmp, int radix)
{
	int	len;

	len = 1;
	*big = 1;
	if (*tmp < 0)
	{
		*tmp *= -1;
		len++;
	}
	while ((*tmp) / (*big) >= radix)
	{
		*big *= radix;
		len++;
	}
	return (len);
}

