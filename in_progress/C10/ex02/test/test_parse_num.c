/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:31:18 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/26 21:23:50 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/utils.h"

typedef struct s_test
{
	long long		expected;
	char			*expected_output;
	char			*input;
	char			*desc;

}					t_test;

long long			parse_num(char *str);

static t_response	is_funct_pass(void *data)
{
	t_response	response;
	t_test		test_func;
	long long	res;

	test_func = *((t_test *)data);
	res = parse_num(test_func.input);
	response.is_pass = res == test_func.expected;
	response.desc = test_func.desc;
	lltoa(res, response.result, 22);
	lltoa(test_func.expected, response.expected, 22);
	return (response);
}

void	test_parse_num(void)
{
	int				size;
	unsigned long	elem_size;

	t_test tests[] = {
		{.expected = -1, .desc = "Parse 'kb'", .input = "kb"},
		{.expected = 1000, .desc = "Parse 'KB'", .input = "KB"},
		{.expected = 100, .desc = "Parse '100'", .input = "100"},
		{.expected = 512, .desc = "Parse 'b'", .input = "b"},
		{.expected = -1, .desc = "Parse ''", .input = ""},
		{.expected = -1, .desc = "Parse '  '", .input = "  "},
		{.expected = 512*100, .desc = "Parse '100b'", .input = "100b"},
		{.expected = -1, .desc = "Parse 'BiB'", .input = "BiB"},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	elem_size = sizeof(tests[0]);
	run_test("parse_num", tests, is_funct_pass, size, elem_size);
}
