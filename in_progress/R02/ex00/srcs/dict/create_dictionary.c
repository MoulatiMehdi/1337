#include "ft.h"

extern char	***g_numbers;

void	skip_whitespace(char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n')
		(*str)++;
}

void	extract_number(char **str, char *number)
{
	int	number_pos;

	number_pos = 0;
	while (**str >= '0' && **str <= '9')
		number[number_pos++] = *(*str)++;
	number[number_pos] = '\0';
}

void	extract_word(char **str, char *word)
{
	int	word_pos;

	word_pos = 0;
	while (**str == ' ' || **str == ':' || **str == '\t')
		(*str)++;
	while (**str >= 32 && **str <= 126)
	{
		if (**str == ' ' && *(*str + 1) == ' ')
		{
			(*str)++;
			continue ;
		}
		word[word_pos++] = *(*str)++;
	}
	word[word_pos] = '\0';
}

void	allocate_and_copy(char **dict_entry, char *number, char *word)
{
	dict_entry[0] = malloc(sizeof(char) * (ft_strlen(number) + 1));
	dict_entry[1] = malloc(sizeof(char) * (ft_strlen(word) + 1));
	ft_strcpy(dict_entry[0], number);
	ft_strcpy(dict_entry[1], word);
}

void	populate(char *str, char ***dict)
{
	char	number[1024];
	char	word[1024];
	int		dict_pos;

	dict_pos = 0;
	while (*str)
	{
		skip_whitespace(&str);
		extract_number(&str, number);
		extract_word(&str, word);
		dict[dict_pos] = malloc(2 * sizeof(char *));
		allocate_and_copy(dict[dict_pos], number, word);
		dict_pos++;
	}
}
