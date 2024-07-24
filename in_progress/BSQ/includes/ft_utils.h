#ifndef FT_UTILS_H
#define FT_UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putstr(char *str);

int	ft_strlen(char *str);
int	min(int a, int b, int c);
int ft_index(char *set, char c);

char ** ft_split(char *str, char *charset);
void *ft_realloc(void* mem,int size);

#endif