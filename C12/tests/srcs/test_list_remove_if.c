/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_if.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 23:35:13 by mmoulati         ###   ########.fr       */
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
	int (*cmp)();
	void * data_ref;
	char* expected;
}					t_request;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *));

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head;
	t_list		*tmp;
	int			i;

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
	ft_list_remove_if(req->size == -1 ? NULL : &head,req->data_ref,req->cmp, NULL);
	ft_list_tostring(res.result,req->size == -1?NULL : &head);
	strcpy(res.expected,req->expected);
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	if(strcmp(res.expected,res.result) != 0)
		res.is_pass = 0;
	return (res);
}

void	test_list_remove_if(void)
{
	int	size;

	char *cases[10][10] = {
		{"A" },
		{"A", "E"},
		{"A", "B", "D"},
		{"A", "B", "C", "E"},
		{"E", "E", "E", "E"},
	};
	t_request	tests[] = {
		{.desc = "NULL List", .strs = NULL, .size=-1,.cmp=strcmp,.data_ref="A",.expected="Null"},
		{.desc = "Empty List", .strs = NULL, .size=0,.cmp=strcmp,.data_ref="A",.expected="Null"},
		{.desc = "Compare function Null", .strs = cases[3], .size=4,.cmp=NULL,.data_ref="A",.expected="E -> C -> B -> A -> Null"},
		{.desc = "One Element - No Match", .strs = cases[0], .size=1,.cmp=strcmp,.data_ref="B",.expected="A -> Null"},
		{.desc = "One Element - One Match", .strs = cases[0], .size=1,.cmp=strcmp,.data_ref="A",.expected="Null"},
		{.desc = "Two element List - No Match", .strs = cases[1], .size=2,.cmp=strcmp,.data_ref="B",.expected="E -> A -> Null"},
		{.desc = "Three element List - No Match", .strs = cases[2], .size=3,.cmp=strcmp,.data_ref="E",.expected= "D -> B -> A -> Null"},
		{.desc = "Four element list - Match Last Element", .strs = cases[3], .size=4,.cmp=strcmp,.data_ref="E",.expected = "C -> B -> A -> Null"},
		{.desc = "Four element list - Match First Element", .strs = cases[3], .size=4,.cmp=strcmp,.data_ref="A",.expected = "E -> C -> B -> Null"},
		{.desc = "Four element list - Match Middle Element", .strs = cases[3], .size=4,.cmp=strcmp,.data_ref="B",.expected = "E -> C -> A -> Null"},
		{.desc = "Four element list - Match All", .strs = cases[4], .size=4,.cmp=strcmp,.data_ref="E",.expected = "Null"},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex12/ft_list_remove_if", tests, is_test_passed, size,
		sizeof(tests[0]));
}
