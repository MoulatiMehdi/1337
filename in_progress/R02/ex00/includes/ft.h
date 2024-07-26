#ifndef CONVERT_NUMBER_TO_WORDS_H
#define CONVERT_NUMBER_TO_WORDS_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int lookup(char *str);
void populate(char *str, char ***dict);
// parse
void extract_word(char **str, char *word);
void extract_number(char **str, char *number);
char *read_dict(char *dict_filename);
int parse_string(char *dictionary_string, char ****dict);
char *parse_number(char *str);

// convert 
int num_to_words(char *numStr, char *buffer);
int convert_hundred(char *numStr, char *buffer);
int convert_ten_unit(char *numStr, char *buffer);
int convert_to_words(int length, char *number, char *buffer);

// print 

void print_error(char *str);
void print_zero(void);
// utils
int ft_strcmp(char *s1, char *s2);
int ft_strlen(char *str);
char *ft_strcpy(char *dest, char *src);
char *ft_strcat(char *dest, char *src);

#endif
