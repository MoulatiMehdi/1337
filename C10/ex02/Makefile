CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = ft_tail

DEPS = ./includes

SRCS = $(wildcard ./srcs/*.c)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(DEPS)

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all 
.PHONY: all re fclean clean
