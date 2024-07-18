CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCFOLDER =./srcs/
INCLFOLDER =./includes/

HEAD = ft.h 
FILES = puts.c ft_atoi.c calc.c do-op.c main.c

SRCS = $(addprefix $(SRCFOLDER),$(FILES))
OBJS = $(SRCS:.c=.o) 
INCL = $(addprefix $(INCLFOLDER),$(HEAD))

NAME = do-op

all : $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c -I$(INCLFOLDER) $< -o $(<:.c=.o)

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all

.PHONY : all fclean re clean
