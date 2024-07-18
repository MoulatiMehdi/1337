#include "ft_string.h"
#include <stdio.h>
#include <unistd.h>

char	*numbers[100][2] = {{"0", "zero"}, {"1", "one"}, {"2", "two"}, {"3",
	"three"}, {"4", "four"}, {"5", "five"}, {"6", "six"}, {"7", "seven"},
	{"8", "eight"}, {"9", "nine"}, {"10", "ten"}, {"11", "eleven"}, {"12",
		"twelve"}, {"13", "thirteen"}, {"14", "fourteen"}, {"15", "fifteen"},
	{"16", "sixteen"}, {"17", "seventeen"}, {"18", "eighteen"}, {"19",
		"nineteen"}, {"20", "twenty"}, {"30", "thirty"}, {"40", "forty"}, {"50",
		"fifty"}, {"60", "sixty"}, {"70", "seventy"}, {"80", "eighty"}, {"90",
		"ninety"}, {"100", "hundred"}, {"1000", "thousand"}, {"1000000",
		"million"}, {"1000000000", "billion"}, {"1000000000000", "trillion"},
	{"1000000000000000", "quadrillion"}, {"1000000000000000000",
		"quintillion"}, {"1000000000000000000000", "sextillion"},
	{"1000000000000000000000000", "septillion"},
	{"1000000000000000000000000000", "octillion"},
	{"1000000000000000000000000000000", "nonillion"},
	{"1000000000000000000000000000000000", "decillion"},
	{"1000000000000000000000000000000000000", "undecillion"}, {(char *)0}};

void	ft_print(char *str)
{
	if (!str || !str[0])
		return ;
	write(1, str, ft_strlen(str));
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

int	lookup(char *str)
{
	int	i;

	i = 0;
	while (numbers[i][0])
	{
		if (ft_strcmp(numbers[i][0], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

// Function to convert hundreds into words
int	convertHundred(char *numStr, char *buffer)
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
	ft_strcat(buffer, numbers[idx_dig][1]);
	ft_strcat(buffer, " ");
	ft_strcat(buffer, numbers[idx_suff][1]);
	if (numStr[1] != '0' || numStr[2] != '0')
		ft_strcat(buffer, " and ");
	return (0);
}

// Function to convert tens and units into words
int	convertTenUnit(char *numStr, char *buffer)
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
	ft_strcat(buffer, numbers[idx_ten][1]);
	if (numStr[0] != '1' && numStr[1] != '0')
	{
		ft_strcat(buffer, "-");
	}
	return (0);
}

// Function to convert number string to words
int	numToWords(char *numStr, char *buffer)
{
	int		len;
	char	nbr[2];
	int		idx_dig;

	len = ft_strlen(numStr);
	if (len == 3)
	{
		if(numStr[0] != '0')
			if (convertHundred(numStr, buffer) < 0)
				return (-1);
		numStr++;
		len--;
	}
	if (len == 2)
	{
		if (numStr[0] == '1')
			return (convertTenUnit(numStr, buffer));
		if (numStr[0] != '0')
			if (convertTenUnit(numStr, buffer) < 0)
				return (-1);
		numStr++;
	}
	if (numStr[0] != '0')
	{
		nbr[0] = numStr[0];
		nbr[1] = '\0';
		idx_dig = lookup(nbr);
		if (idx_dig == -1)
			return (-1);
		ft_strcat(buffer, numbers[idx_dig][1]);
	}
	return (0);
}

int	print_three_digits(char digits[], int order, char *buffer)
{
	int test;

	test = numToWords(digits,buffer);

	if(test < 0)
		return test;
	if(order != 0)
	{
	}
	return 0;
}

int	hala(int length, char *number, char *buffer)
{
	char	digits[4] = {'0', '0', '0',0};
	int index;
	if (length <= 0)
	{
		// print buffer
		return 0;
	}
	hala(length - 3, number, buffer);


	digits[2] = number[length - 1]; // TODO: Might be a bug here
	if (length - 2 >= 0)
		digits[1] = number[length - 2];
	if (length - 3 >= 0)
		digits[0] = number[length - 3];

	printf(" -> %s \n", number);
	printf("level %d string %s \n",length,digits);
	numToWords(digits, buffer);
	/*	index = lookup(magnitude(length));

	if(index < 0)
		return -1;
	ft_strcat(buffer," ");
	ft_strcat(buffer,numbers[index][1]);
*/
	(void) index;
	return 0;
}

void	print_3_digits(char *digit, char *buffer)
{
	if (digit[0] > '0')
	{
	}
	(void)buffer;
}
