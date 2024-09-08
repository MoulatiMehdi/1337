#include "utils.h"

void	msg_pass(char *str)
{
	printf("\t" GREEN CHECK GRAY "  %s" DEFAULT "\n", str);
}

void	msg_fail(char *desc, char *expected, char *result)
{
	printf(TAB RED CROSS GRAY " %s" DEFAULT "\n", desc);
	printf(TAB "Expected : '%s'\n",expected);
	printf(TAB "Got      : '%s'\n" DEFAULT,  result);
}

void	msg_status(char *func_name, int errors)
{
	printf(errors ? FAIL : PASS);
	printf(" %s\n" DEFAULT, func_name);
}
