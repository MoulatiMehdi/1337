CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = ft_hexdump

DEPS = ./includes/

SRCS = $(wildcard ./srcs/*.c) $(wildcard ./utils/*.c) 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c ./includes/ft.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(DEPS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all 
.PHONY: all re fclean clean
