#include "ft.h"

t_list	*create_list(t_array arr)
{
	int		i;
	t_list	*tmp;
	t_list	*head;

	i = arr.length - 1;
	head = 0;
	if (arr.strs)
	{
		while (i >= 0)
		{
			tmp = head;
			head = ft_create_elem(arr.strs[i]);
			head->next = tmp;
			i--;
		}
	}
	return (head);
}
void	clear_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
