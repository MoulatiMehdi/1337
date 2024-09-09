/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/10 00:47:43 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_list.h"
#include "stdlib.h"
#include "string.h"
#include "utils.h"

typedef struct s_request
{
	char			*desc;
	void			*input;
	t_list			**head;

}					t_request;
void				ft_list_push_front(t_list **begin_list, void *data);

void	ft_list_tostring(char *buffer, t_list **head)
{
	t_list	*p;

	buffer[0] = '\0';
	if (head && *head)
	{
		p = *head;
		while (p)
		{
			strcat(buffer, p->data);
			p = p->next;
		}
	}
	strcat(buffer, "Null");
}

static t_response	is_test_passed(t_request *req)
{
	t_list		*p;
	t_response	res;

	// Initialize res.result and res.expected before usage
	memset(res.result, 0, sizeof(res.result));
	memset(res.expected, 0, sizeof(res.expected));
	p = NULL;
	if (req->head)
		p = *req->head;
	ft_list_push_front(req->head, req->input);
	res.desc = req->desc;
	res.is_pass = 0;
	ft_list_tostring(res.result, req->head);
	if (req->head && *req->head != p && (*req->head)->next == p
		&& (*req->head)->data == req->input)
		res.is_pass = 1;
	if (p)
		free(p);
	return (res);
}

void	test_push_front(void)
{
	int		size;
	t_list	*p_null;
	t_list	*head;

	t_request tests[] = {
		{.desc = "Null Head", .input = "Z", .head = NULL},
		{.desc = "String Data", .input = "Z", .head = &p_null},
		{.desc = "Number Data", .input = "Z", .head = &head},
	};
	p_null = NULL;
	head = ft_create_elem("A");
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ft_list_push_front", tests, is_test_passed, size,
		sizeof(tests[0]));
}
