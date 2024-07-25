#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*magnitude(int length);
int		numToWords(char *numStr, char *buffer);
int		lookup(char *str);
int print_three_digits(char *digit,int order,char *buffer);
void	hala(int length, char *number, char *buffer);
int	main(int argc, char **argv)
{
	char	buffer[1000];

	(void) argc;
	//if (argc != 3)
	//	return (0);
	///printf("'%s'\n", numToWords(argv[1], buffer) < 0 ? "Not Found" : "GOOD");
	
	hala(strlen(argv[1]),argv[1],buffer);
	printf("'%s'\n", buffer);
	/**printf("Magnitude function test\n");
	for(int i = 1; i < 12 ; i ++ )
	{
		printf("i: %2d -> %s\n",i,magnitude(i));
	}**/
}
