#include "ft.h"

extern char	***g_numbers;

int	handle_hundreds(char **numStr, char *buffer)
{
	if (**numStr != '0')
		if (convert_hundred(*numStr, buffer) < 0)
			return (-1);
	(*numStr)++;
	return (0);
}

int	handle_tens(char **numStr, char *buffer)
{
	if (**numStr == '1')
		return (convert_ten_unit(*numStr, buffer));
	if (**numStr != '0')
		if (convert_ten_unit(*numStr, buffer) < 0)
			return (-1);
	(*numStr)++;
	return (0);
}

int	handle_units(char **numStr, char *buffer)
{
	char	nbr[2];
	int		idx_dig;

	if (**numStr != '0')
	{
		nbr[0] = **numStr;
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
	}
	if (len == 2)
	{
		if (handle_tens(&numStr, buffer) < 0)
			return (-1);
	}
	if (handle_units(&numStr, buffer) < 0)
		return (-1);
	return (0);
}
