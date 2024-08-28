CC = cc 
CFLAGS = -Wall -Wextra -fsanitize=address -g


SRCS = ../srcs/parse.c ./main.c $(wildcard ./test_*.c) ../srcs/ft_strlen.c $(wildcard ./utils/*.c)
DEPS = ./includes/ 
OBJS =$(SRCS:.c=.o)

NAME = test

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	
	$(CC) $(CFLAGS) -c -o $@ $<  -I$(DEPS)
clean : 
	rm -f $(OBJS)
fclean :  clean 
	rm -f $(NAME)

re : fclean all 

.PHONY: re clean fclean all test
