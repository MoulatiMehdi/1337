CC=gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs/
UTLS_DIR = utils/
HEAD_DIR = ./includes/

UTLS_FILES = ft_index.c ft_math.c ft_putstr.c ft_split.c ft_strlen.c 
SRCS_FILES = allocate.c solve.c $(addprefix $(UTLS_DIR),$(UTLS_FILES)) 

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_FILES)) ./tests/main.c
OBJS = $(SRCS:.c=.o)

NAME = solve

all :  $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(HEAD_DIR)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 


clean :  
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all 

.PHONY : re fclean clean all 