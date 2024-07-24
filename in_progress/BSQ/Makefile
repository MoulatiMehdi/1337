CC = gcc
CFLAGS = -Wall -Wextra -Werror 

SRCS_DIR = ./srcs/
TEST_DIR = ./test/
UTLS_DIR = ./utils/

UTLS = $(addprefix $(UTLS_DIR),$(UTLS_FILES))

SRCS_FILES = read.c $(UTLS) 
UTLS_FILES = ft_realloc.c
TEST_FILES = main.c 

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_FILES)) $(addprefix $(TEST_DIR),$(TEST_FILES)) 
OBJS = $(SRCS:.c=.o)
DEPS =./includes/

NAME = read.exe

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


%.o : %.c 
	$(CC) $(CFLAGS) -c  $< -o $@ -I$(DEPS)

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all 

.PHONY : fclean all clean re 


