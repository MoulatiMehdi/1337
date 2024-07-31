CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_display_file

SRC = ft_display_file.c

OBJS = $(SRC:.c=.o)


all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

.PHONY: all re fclean clean
