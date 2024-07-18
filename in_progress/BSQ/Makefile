CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = file.c math.c solve.c ft_strlen.c solve.c allocate.c 
SRCFOLDER = ./srcs/

SRCS  = $(addprefix $(SRCFOLDER), $(FILES))
HEAD = ./includes/
OBJS = $(SRCS:.c=.o)

NAME = bsq


all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEAD)


clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean all re clean 
