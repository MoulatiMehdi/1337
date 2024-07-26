#include "ft.h"

extern char	***g_numbers;

char	*read_dict(char *dict_filename)
{
	char	buffer[30000];
	char	*string;
	int		fd;
	int		bytes_read;

	fd = open(dict_filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("Dict Error");
		return (NULL);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		print_error("Dict Error");
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	string = malloc(sizeof(char) * (bytes_read + 1));
	ft_strcpy(string, buffer);
	close(fd);
	return (string);
}

int	check_dictionary_is_valid(char *str)
{
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		while (*str >= '0' && *str <= '9')
			str++;
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str != ':')
			return (0);
		else
			str++;
		while (*str == ' ' || *str == '\t')
			str++;
		while (*str >= 32 && *str <= 126)
			str++;
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str != '\n' && *str != '\0')
			return (0);
		str++;
	}
	return (1);
}

int	count_dictionary_entries(char *str)
{
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (*str != '\n')
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int	parse_string(char *dictionary_string, char ****dict)
{
	int	count;

	if (!check_dictionary_is_valid(dictionary_string))
	{
		print_error("Dict Error");
		return (0);
	}
	count = count_dictionary_entries(dictionary_string) + 1;
	*dict = malloc(sizeof(char **) * count);
	populate(dictionary_string, *dict);
	return (1);
}
