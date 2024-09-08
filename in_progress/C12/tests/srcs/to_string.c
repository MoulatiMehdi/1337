#include "ft.h"

void	values_to_string(char *buffer, void *data, t_list *next)
{
	sprintf(buffer, "\n%sitem :\n%s\tdata : %p\n%s\tnext : %p\n", TAB TAB,
		TAB TAB, data, TAB TAB, next);
}

char	*to_string(char *buffer, t_list *p)
{
	if (!p)
		sprintf(buffer, "\n" TAB TAB "item : %p", NULL);
	else
		values_to_string(buffer, p->data, p->next);
	return (buffer);
}
