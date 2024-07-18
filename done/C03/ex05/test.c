#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(int argc, char **argv)
{
	unsigned	size;
	char		*src;
	char		dest[100] = "hello";
	char		b_dest[100] = "hello";

	if (argc < 3)
		return (-1);
	size = atoi(argv[2]);
	src = argv[1];
	printf("%lu\n", strlen(dest));
	printf("%lu\n", strlen(b_dest));
	printf("\tstring : '%s'\n", argv[1]);
	printf("-----------------------\n");
	printf("\tcustom	: \nsize\t: %u\nstring\t: '%s'\n", ft_strlcat(dest, src,
				size), dest);
	printf("\tbuildin	: \nsize\t:%lu\nstring\t: '%s'\n", strlcat(b_dest, src,
				size), b_dest);
}
