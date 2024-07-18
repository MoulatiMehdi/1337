#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int argc, char **argv)
{
	char	*str_nbr;
	char	*base_from;
	char	*base_to;

	if (argc != 4)
		return (-1);
	str_nbr = argv[1];
	base_from = argv[2];
	base_to = argv[3];
	printf("number to convert\t\t: %s\n", str_nbr);
	printf("base_from\t\t: %s\n", base_from);
	printf("base_to\t\t: %s\n", base_to);
	printf("convert from %ld to %ld :\n", strlen(base_from), strlen(base_to));
	printf("%s", ft_convert_base(str_nbr, base_from, base_to));
}
