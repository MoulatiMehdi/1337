#include "utils.h"

void	msg_pass(char *str)
{
	printf("\t" GREEN CHECK GRAY "  %s" DEFAULT "\n", str);
}

void	msg_fail(char *desc, char *expected, char *result)
{
	printf(TAB RED CROSS GRAY " %s" DEFAULT "\n", desc);
	printf(TAB TAB GRAY "Expected : '%s'\n",expected);
	printf(TAB TAB GRAY"Got      : '%s'\n" DEFAULT,  result);
}

void	msg_status(char *func_name, int errors)
{
	printf("%s ",errors ? FAIL : PASS);
	printf("%s\n\n\n" DEFAULT, func_name);
}
