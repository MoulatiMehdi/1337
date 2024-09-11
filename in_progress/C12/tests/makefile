CC = cc 
CFLAGS = -Wall -Wextra -fsanitize=address -g


SRCS=$(wildcard ./srcs/*.c) $(wildcard ./utils/*.c) $(wildcard ../ex*/*.c)
DEPS=./includes/ ../
OBJS=$(SRCS:.c=.o)

NAME = test

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c $(DEPS)
	
	$(CC) $(CFLAGS) -c $(addprefix -I,$(DEPS)) -o $@ $< 
clean : 
	rm -f $(OBJS)
fclean :  clean 
	rm -f $(NAME)

re : fclean all  clean

.PHONY: re clean fclean all test
