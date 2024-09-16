
#include <limits.h>
#include <stdio.h>

void	lltoa(long long value, char *buffer, int size)
{
	snprintf(buffer, size, "%lld", value);
}
