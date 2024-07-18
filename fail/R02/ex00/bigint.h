#ifndef BIGINT_H
#include <ft_string.h>
#define BIGINT_H

int	ft_subtract_char(char *res, char *b, int depth, int max)
{
	int	rest;
	int	c;

	rest = 0;
	if (depth < max - 1)
		rest = ft_subtract_char(res, b, depth + 1, max);
	c = res[depth] - b[depth] + rest;
	if (c >= 0)
	{
		b[depth] = c + '0';
		return (0);
	}
	b[depth] = 10 + c + '0';
	return (-1);
}

/**
 *	subtract two strings
 *	! 'a' must be bigger than 'b'
 *	if not it wil return null
 */
char	*ft_subtract(char *a, char *b)
{
	int		max;
	int		b_size;
	char	*res;

	max = ft_strlen(a);
	b_size = ft_strlen(b);
	if (max < b_size)
		max = b_size;
	res = ft_pad_start(b, max, '0');
	if (ft_subtract_char(a, res, 0, max) < 0)
		return (NULL);
	return (res);
}

#endif
