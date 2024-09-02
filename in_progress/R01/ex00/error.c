#include <unistd.h>

void error(void)
{
	write(2,"ERROR\n",6);
}
