#include <stdio.h>
#include <stdlib.h>

int		ft_count_word(char *str, char *sep);
char	**ft_split(char *str, char *charset);
int	main(int argc, char **argv)
{
	char	**strs;

	if (argc != 3)
		return (1);
	// printf("'%s' -> %d\n",argv[1],ft_count_word(argv[1],argv[2]));
	strs = ft_split(argv[1], argv[2]);
	if (strs == 0)
		printf("EMPTY ARRAY\n");
	else
		for (int i = 0; strs[i] != 0; i++)
		{
			printf("'%s'\n", strs[i]);
		}
}
