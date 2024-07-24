CC = gcc
CFLAGS = -Wall -Wextra -Werror 

SRCS_DIR = ./srcs/
TEST_DIR = ./test/

SRCS_FILES = read.c
TEST_FILES = main.c 

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_FILES)) $(addprefix $(TEST_DIR),$(TEST_FILES))
OBJS = $(SRCS:.c=.o)
DEPS =. 

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


