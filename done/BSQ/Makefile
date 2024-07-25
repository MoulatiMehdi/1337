CC = gcc 
CFLAGS = -Wall -Wextra -Werror 

SRCS_DIR = ./srcs/
UTLS_DIR = ./utils/
DEPS_DIR = ./includes/

UTLS_FILES = ft_index.c ft_math.c ft_putstr.c ft_realloc.c ft_split.c ft_strlen.c 

UTLS = $(addprefix $(UTLS_DIR),$(UTLS_FILES))
SRCS_FILES = $(UTLS) allocate.c validate.c read.c parse.c map.c solve.c 

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_FILES)) main.c
OBJS = $(SRCS:.c=.o)
NAME = bsq

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c 
	$(CC) $(CFLAGS) -c  $< -o $@ -I$(DEPS_DIR)

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)
	
re : fclean all 

.PHONY: re fclean clean all 
