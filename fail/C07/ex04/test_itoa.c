#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_itoa_base(int nbr, char *base, int radix);

int	main(int argc, char **argv)
{
	char	*str_nbr;
	char	*base;
	int		nbr;
	int		radix;
	char	*res;

	if (argc != 3)
		return (-1);
	str_nbr = argv[1];
	base = argv[2];
	radix = strlen(base);
	nbr = atoi(str_nbr);
	res = ft_itoa_base(nbr, base, radix);
	printf("str_nbr : %s\nbase : %s\nradix: %d\n", str_nbr, base, radix);
	printf("%s ----> %s\n", str_nbr, res);
	printf("%s ----> %c%x\n", str_nbr, nbr < 0 ? '-' : '\0', abs(nbr));
	printf("length : %lu", strlen(res));
}
