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

void	ft_list_tostring(char *buffer, t_list **head)
{
	t_list	*p;

	buffer[0] = '\0';
	if (head && *head)
	{
		p = *head;
		while (p)
		{
			strcat(buffer, p->data?p->data:"NULL");
			strcat(buffer, " -> ");
			p = p->next;
		}
	}
	strcat(buffer, "Null");
}
