#include "ft.h"
extern char	***g_numbers;

void	set_digits(int span, char *number, int index, char *digits)
{
	digits[0] = '0';
	digits[1] = '0';
	digits[2] = '0';
	if (span == 3)
	{
		digits[0] = number[index + 0];
		digits[1] = number[index + 1];
		digits[2] = number[index + 2];
	}
	else if (span == 2)
	{
		digits[1] = number[index + 0];
		digits[2] = number[index + 1];
	}
	else if (span == 1)
	{
		digits[2] = number[index + 0];
	}
}

char	*magnitude(int length)
{
	char	*p;
	int		size;
	int		i;

	i = 0;
	size = ((length - 1) / 3) * 3;
	p = (char *)malloc((size + 2) * sizeof(char));
	if (p == NULL)
		return (NULL);
	p[0] = '1';
	while (i < size)
	{
		p[i + 1] = '0';
		i++;
	}
	return (p);
}

int	process_order_of_magnitude(int length)
{
	char	*order_of_magnitude;
	int		order_index;

	order_of_magnitude = magnitude(length);
	order_index = lookup(order_of_magnitude);
	if (order_index == -1)
	{
		print_error("Dict Error");
		return (0);
	}
	return (1);
}

void	update_buffer_with_magnitude(int length, char *buffer)
{
	char	*order_of_magnitude;
	int		order_index;
	char	*order_in_words;

	if(length <= 3)
		return ;
	order_of_magnitude = magnitude(length);
	order_index = lookup(order_of_magnitude);
	order_in_words = g_numbers[order_index][1];
	if (ft_strlen(order_of_magnitude) != 1)
	{
		ft_strcat(buffer, " ");
		ft_strcat(buffer, order_in_words);
	}
	ft_strcat(buffer, " ");
}


int	convert_to_words(int length, char *number, char *buffer)
{
	int		span;
	int		index;
	char	digits[4] ;

	digits[3] = 0;
	span = length - ((length - 1) / 3) * 3;
	index = 0;
	while (length > 0)
	{
		if (!process_order_of_magnitude(length))
			return (0);
		set_digits(span, number, index, digits);

		num_to_words(digits, buffer);
		if(digits[0] != '0' || digits[1]!= '0' || digits[2] !='0')
			update_buffer_with_magnitude(length, buffer);
		index += span;
		length -= span;
		if (span != 3)
			span = 3;
	}
	return (1);
}


