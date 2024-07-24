#ifndef FT_UTILS_H
#define FT_UTILS_H

#define BUFF_SIZE 1024

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void *ft_realloc(void *mem, int size);
void	ft_putstr(char *str);

int	ft_strlen(char *str);
int	min(int a, int b, int c);
int ft_index(char *set, char c);

char ** ft_split(char *str, char *charset);

#endif