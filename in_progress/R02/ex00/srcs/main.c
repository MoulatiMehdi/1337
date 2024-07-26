#include <stdio.h>
#include "ft.h"

char	***g_numbers;

int	main(int argc, char *argv[])
{
	char	*input_number;
	char	*dictionary_string;
	char	***dict;
	char	buffer[2048];

	buffer[0] = '\0';

	input_number = parse_number(argv[argc - 1]);
	if (input_number == NULL)
	{
		print_error("Error");
		return (1);
	}
	if (argc == 3)
		dictionary_string = read_dict(argv[1]);
	else if (argc == 2)
		dictionary_string = read_dict("default.dict");
	if (dictionary_string == NULL)
		return (1);
	if (!parse_string(dictionary_string, &dict))
		return (1);
	g_numbers = dict;
	if (input_number[0] != '0')
		convert_to_words(ft_strlen(input_number), input_number, buffer);
	else
		print_zero();
	printf("%s\n", buffer);
	return (0);
}
