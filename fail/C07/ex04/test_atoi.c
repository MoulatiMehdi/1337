#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi_base(char *str, char *base, int radix);

int	main(int argc, char **argv)
{
	char	*nbr_str;
	char	*base;
	int		radix;
	int		res;

	if (argc != 3)
		return (-1);
	nbr_str = argv[1];
	base = argv[2];
	radix = strlen(base);
	res = ft_atoi_base(nbr_str, base, radix);
	printf("intput\n\tbase %d\t: '%s'\n", radix, nbr_str);
	printf("output:\n\tbase 10\t: %d\n", res);
}
