#include "ft.h"

extern char	***g_numbers;

int	lookup(char *str)
{
	int	i;

	i = 0;
	while (g_numbers[i][0])
	{
		if (ft_strcmp(g_numbers[i][0], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	print_zero(void)
{
	int		index;
	char	*word;

	index = lookup("0");
	if (index == -1)
	{
		print_error("Dict Error");
		return ;
	}
	word = g_numbers[index][1];
	write(1, word, ft_strlen(word));
}
