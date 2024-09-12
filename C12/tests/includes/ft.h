#ifndef FT_FT_H
#define FT_FT_H
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
#include "utils.h"

typedef struct s_array
{
	char			**strs;
	int				length;
}					t_array;
void	values_to_string(char *buffer, void *data, t_list *next);
char	*to_string(char *buffer, t_list *p);
void	ft_list_tostring(char *buffer, t_list **head);

t_list	*create_list(t_array arr);
void	clear_list(t_list *head);

#endif 
