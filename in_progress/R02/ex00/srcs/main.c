#include <stdio.h>
#include "ft.h"

char	***g_numbers;

int	main(int argc, char *argv[])
{
	char *dict_name;
	char	*input;
	char	*dict_str;
	char	***dict;
	char	buffer[2048];

	buffer[0] = '\0';
	dict_name = "default.dict";

	input = parse_number(argv[argc - 1]);
	if (input == NULL)
	{
		print_error("Error\n");
		return (1);
	}
	if (argc == 3)
		dict_name = argv[1];
	dict_str = read_dict(dict_name);
	if (dict_str == NULL || !parse_string(dict_str, &dict))
	{
		print_error("Dict Error\n");
		return (1);
	}
	g_numbers = dict;
	if (input[0] != '0')
	{
		if(convert_to_words(input, buffer))
			printf("%s\n", buffer);
	}
	else
		print_zero();
	return (0);
}
