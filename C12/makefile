CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = $(wildcard ./ex*/*.c) 
DEPS = ./ 
OBJS = $(SRCS:.c=.o)
NAME = test 

all : $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DEPS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)
fclean : clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean 
