
CC=cc
CFLAGS=-g -fsanitize=address
SRCS=$(wildcard ./ex*/*.c)
OBJS=$(SRCS:.c=.o)
DEPS=./
NAME=test

all : $(NAME)

$(NAME) : $(SRCS) ft_btree.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I$(DEPS)

clean :
	rm -rf $(OBJS)
fclean : clean 
	rm -rf	$(NAME)
re : fclean all

.PHONY : re fclean clean all 


