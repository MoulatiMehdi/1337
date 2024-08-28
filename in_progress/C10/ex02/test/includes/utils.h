#ifndef UTILS_H

# define UTILS_H

# include <stdio.h>

# define RED "\x1b[1;91m"
# define BLUE "\x1b[1;96m"
# define GREEN "\x1b[1;92m"
# define YELLOW "\x1b[1;93m"
# define DEFAULT "\x1b[0m"
# define GRAY "\x1b[1;90m"

# define CROSS "\u274c"
# define CHECK "\u2714"
# define PASS "\x1b[1;37;102m PASS \x1b[0m"
# define FAIL "\x1b[1;37;101m FAIL \x1b[0m"

typedef struct s_response
{
	char	result[1024];
	char	expected[1024];
	char	*desc;
	int		is_pass;
}			t_response;

void	msg_pass(char *str);
void	msg_fail(char *desc, char *expected, char *result);
void	msg_status(char *func_name, int state);
void	lltoa(long long value, char *buffer, int size);

void					run_test(char *func_name, void *tests,
							t_response (*f)(void *), int size,
							unsigned long elem_size);

#endif
