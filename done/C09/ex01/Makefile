## Commands
CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rc
LIB = ranlib

# Folders

FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRC =  ./srcs/

# Files 
SRCS = $(addprefix $(SRC),$(FILES))
HEAD = ./includes/
OBJS = $(SRCS:.c=.o)
NAME = libft.a

## Rules
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS) 
	$(LIB) $(NAME)
.c.o:
	$(CC) $(CFLAGS) -I$(HEAD) -c $< -o $(<:.c=.o) 

clean : 
	rm -f $(OBJS)

fclean :  clean 
	rm -f  $(NAME)

re : fclean all

.PHONY: re all fclean clean 


