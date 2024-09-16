CC = cc 
CFLAGS = -Wall -Wextra -fsanitize=address -g


SRCS=$(wildcard ./srcs/*.c) $(wildcard ./utils/*.c) $(wildcard ../ex*/*.c)
DEPS=./includes/ ../
OBJS=$(SRCS:.c=.o)

NAME = test

all : $(NAME)

$(NAME) : $(SRCS) $(wildcard ./includes/*.h)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(addprefix -I,$(DEPS))
clean : 
	rm -f $(OBJS)
fclean :  clean 
	rm -f $(NAME)

re : fclean all  

.PHONY: re clean fclean all test
