#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define NUMBER_LENGTH 40

typedef struct
{
	char	*number;
	char	*word;
}			NumberWord;

int	readDictionary(const char *filename, NumberWord **dictionary)
{
	FILE	*file;
	int		count;
	int		capacity;
	char	number[NUMBER_LENGTH];
	char	word[NUMBER_LENGTH];
	int		i;

	file = fopen(filename, "r");
	if (!file)
	{
		perror("Error opening file");
		return (-1);
	}
	count = 0;
	capacity = INITIAL_SIZE;
	*dictionary = malloc(capacity * sizeof(NumberWord));
	if (!*dictionary)
	{
		perror("Error allocating memory");
		fclose(file);
		return (-1);
	}
	while (fscanf(file, "%s %s", number, word) != EOF)
	{
		if (count >= capacity)
		{
			capacity *= 2;
			*dictionary = realloc(*dictionary, capacity * sizeof(NumberWord));
			if (!*dictionary)
			{
				perror("Error reallocating memory");
				fclose(file);
				return (-1);
			}
		}
		i = 0;
		while (number[i] >= '0' && number[i] <= '9')
			i++;
		number[i] = '\0';
		(*dictionary)[count].number = strdup(number);
		(*dictionary)[count].word = strdup(word);
		count++;
	}
	fclose(file);
	return (count);
}

void	printDictionary(NumberWord *dictionary, int entries)
{
	for (int i = 0; i < entries; i++)
	{
		printf("'%s': '%s'\n", dictionary[i].number, dictionary[i].word);
	}
}

const char	*findWord(const char *number, NumberWord *dictionary, int entries)
{
	for (int i = 0; i < entries; i++)
	{
		if (strcmp(dictionary[i].number, number) == 0)
		{
			return (dictionary[i].word);
		}
	}
	return (NULL);
}

void	numberToWords(const char *number, NumberWord *dictionary, int entries,
		char *result)
{
	char	temp[NUMBER_LENGTH];
	int		len;
	int		pos;
	int		digit;

	if (strcmp(number, "0") == 0)
	{
		strcpy(result, findWord("0", dictionary, entries));
		return ;
	}
	result[0] = '\0';
	len = strlen(number);
	pos = 0;
	while (pos < len)
	{
		digit = number[pos] - '0';
		sprintf(temp, "%d", digit);
		strcat(result, findWord(temp, dictionary, entries));
		strcat(result, " ");
		pos++;
	}
	len = strlen(result);
	if (len > 0 && result[len - 1] == ' ')
	{
		result[len - 1] = '\0';
	}
}
