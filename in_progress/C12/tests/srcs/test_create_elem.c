/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/08 20:39:23 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"
#include "string.h"
#include "utils.h"
#include "ft.h"

typedef struct s_request
{
	char	*desc;
	void	*input;

}			t_request;

t_response	is_test_passed(t_request *req)
{
	t_list		*p;
	t_response	res;

	// Initialize res.result and res.expected before usage
	memset(res.result, 0, sizeof(res.result));
	memset(res.expected, 0, sizeof(res.expected));
	p = ft_create_elem(req->input);
	res.desc = req->desc;
	res.is_pass = 0;
	to_string(res.result, p);
	values_to_string(res.expected, req->input, NULL);
	if (p && !p->next && p->data == req->input)
		res.is_pass = 1;
	if (p)
		free(p);
	return (res);
}

void	test_create_elem(void)
{
	int	size;

	t_request tests[] = {
		{.desc = "Null Data", .input = NULL},
		{.desc = "String Data", .input = "Hello world"},
		{.desc = "Number Data", .input = &size},
		{.desc = "Structure Data", .input = tests},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ft_create_elem", tests, is_test_passed, size, sizeof(tests[0]));
}
