/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_offset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:31:18 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/26 21:07:43 by mehdi            ###   ########.fr       */
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

long long			offset(char *str);

static t_response	is_funct_pass(void *data)
{
	t_response	response;
	t_test		test_func;
	long long	res;

	test_func = *((t_test *)data);
	res = offset(test_func.input);
	response.is_pass = res == test_func.expected;
	response.desc = test_func.desc;
	lltoa(res, response.result, 22);
	lltoa(test_func.expected, response.expected, 22);
	return (response);
}

void	test_offset(void)
{
	int				size;
	unsigned long	elem_size;

	t_test tests[] = {
		{.expected = -1, .desc = "Parse 'kb'", .input = "kb"},
		{.expected = 1000, .desc = "Parse 'KB'", .input = "KB"},
		{.expected = 1000, .desc = "Parse 'kB'", .input = "kB"},
		{.expected = 1, .desc = "Parse ''", .input = ""},
		{.expected = 512, .desc = "Parse 'b'", .input = "b"},
		{.expected = 512, .desc = "Parse 'B'", .input = "B"},
		{.expected = 1024, .desc = "Parse 'K'", .input = "K"},
		{.expected = 1024, .desc = "Parse 'KiB'", .input = "KiB"},
		{.expected = 1024*1024, .desc = "Parse 'M'", .input = "M"},
		{.expected = 1024*1024, .desc = "Parse 'MiB'", .input = "MiB"},
		{.expected = -1, .desc = "Parse 'MIB'", .input = "MIB"},
		{.expected = -1, .desc = "Parse 'Mib'", .input = "Mib"},
		{.expected = -1, .desc = "Parse ' MiB'", .input = " MiB"},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	elem_size = sizeof(tests[0]);
	run_test("offset", tests, is_funct_pass, size, elem_size);
}
