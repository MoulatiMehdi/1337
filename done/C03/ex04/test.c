#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(int argc, char **argv)
{
	char	src[] = "hello\0";
	char	des[] = "\0";

	if (argc < 3)
		(void)argc;
	(void)argv;
	printf("string	: '%s'\n", src);
	printf("to_find	: '%s'\n", des);
	printf("\tresult	: '%s'\n", ft_strstr(src, des));
	printf("\tbuildin	: '%s'\n", strstr(src, des));
	printf("%d", strstr(src, des) == ft_strstr(src, des));
}
