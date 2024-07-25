#include <unistd.h>
#include <stdlib.h>

unsigned int ft_validate(char * str);
void solve(char *str);
void error(void);

int main(int argc,char ** argv)
{
	if(argc != 2)
	{
		error();
		return -1;
	}
	if(!ft_validate(argv[1])){
		error();
		return -2;
	}

	
	solve(argv[1]);
	return 0;
}
