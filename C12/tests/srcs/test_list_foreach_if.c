/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_foreach_if.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 20:16:48 by mmoulati         ###   ########.fr       */
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
	char			**strs;
	int				size;
	void			(*f)(void *);
	int (*cmp)();
	void * data_ref;
}					t_request;

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),void *data_ref, int (*cmp)());
static char g_buffer[1024];

static void	print(void *data)
{
	strcat(g_buffer,data?(char*)data : "(null)");
	strcat(g_buffer,"->");
}

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head;
	t_list		*tmp;
	int			i;
	
	g_buffer[0] = 0;
	init_response(&res, req->desc);
	i = 0;
	head = 0;
	tmp = 0;
	if (req->strs && req->size > 0)
	{
		while (i < req->size)
		{
			tmp = head;
			head = ft_create_elem(req->strs[i]);
			head->next = tmp;
			i++;
		}
	}
	i = 0;
	tmp = head;
	res.is_pass = 1;
	ft_list_foreach_if(head, req->f,req->data_ref,req->cmp);

	strcpy(res.result,g_buffer);
	g_buffer[0] = 0;
	while (head)
	{
		if(req->f && req->cmp(req->data_ref,head->data) == 0)	
			req->f(head->data);
		tmp = head->next;
		free(head);
		head = tmp;
	}
	strcpy(res.expected,g_buffer);
	if(strcmp(res.expected,res.result) != 0)
		res.is_pass = 0;
	return (res);
}

void	test_list_foreach_if(void)
{
	int	size;

	char *cases[10][10] = {
		{"A" },
		{"A", "E"},
		{"A", "B", "D"},
		{"A", "B", "C", "E"},
	};
	t_request	tests[] = {
		{.desc = "Empty List", .strs = NULL, .size=0,.f=print,.cmp=strcmp,.data_ref="A"},
		{.desc = "Compare function Null", .strs = NULL, .size=0,.f=print,.cmp=NULL,.data_ref="A"},
		{.desc = "fct function Null", .strs = NULL, .size=0,.f=NULL,.cmp=strcmp,.data_ref="A"},
		{.desc = "One Element", .strs = cases[0], .size=1,.f=print,.cmp=strcmp,.data_ref="B"},
		{.desc = "Two element List", .strs = cases[1], .size=2,.f=print,.cmp=strcmp,.data_ref="B"},
		{.desc = "Three element List", .strs = cases[2], .size=3,.f=print,.cmp=strcmp,.data_ref="E"},
		{.desc = "Four element list", .strs = cases[3], .size=4,.f=print,.cmp=strcmp,.data_ref="E"},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex10/ft_list_foreach_if", tests, is_test_passed, size,
		sizeof(tests[0]));
}
