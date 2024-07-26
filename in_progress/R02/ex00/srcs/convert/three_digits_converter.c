#include "ft.h"

extern char	***g_numbers;

int	convert_hundred(char *numStr, char *buffer)
{
	char	nbr[2];
	int		idx_dig;
	int		idx_suff;

	nbr[0] = numStr[0];
	nbr[1] = '\0';
	idx_dig = lookup(nbr);
	idx_suff = lookup("100");
	if (idx_dig == -1 || idx_suff == -1)
		return (-1);
	ft_strcat(buffer, g_numbers[idx_dig][1]);
	ft_strcat(buffer, " ");
	ft_strcat(buffer, g_numbers[idx_suff][1]);
	ft_strcat(buffer, " ");
	return (0);
}

int	convert_ten_unit(char *numStr, char *buffer)
{
	char	nbr[3];
	int		idx_ten;

	nbr[0] = numStr[0];
	if (nbr[0] != '1')
		nbr[1] = '0';
	else
		nbr[1] = numStr[1];
	nbr[2] = '\0';
	idx_ten = lookup(nbr);
	if (idx_ten == -1)
		return (-1);
	ft_strcat(buffer, g_numbers[idx_ten][1]);
	if (numStr[0] != '1' && numStr[1] != '0')
	{
		ft_strcat(buffer, " ");
	}
	return (0);
}
