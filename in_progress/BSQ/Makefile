CC = gcc 
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs/
UTLS_DIR =  utils/
DEPS_DIR = ./includes/ 

UTLS_FILES = ft_index.c ft_math.c ft_putstr.c ft_split.c ft_strlen.c

UTLS = $(addprefix $(UTLS_DIR),$(UTLS_FILES))
SRCS_FILES = map.c parse.c validate.c allocate.c $(UTLS)

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS = $(SRCS:.c=.o)
NAME = create.exe 

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DEPS_DIR)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


clean : 
	rm -f $(OBJS)

fclean : clean  
	rm -f $(NAME)

re : fclean all 

.PHONY : re clean fclean all 
