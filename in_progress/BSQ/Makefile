CC= gcc
FLAGS=-Werror -Wall -Wextra 

UTILSFOLDER = utils/
SRCSFOLDER =  ./srcs/

UTILSFILES = ft_index.c ft_putstr.c ft_strlen.c 
SRCSFILES = parse.c validate.c $(addprefix $(UTILSFOLDER),$(UTILSFILES))

SRCS= ./tests/main.c $(addprefix $(SRCSFOLDER),$(SRCSFILES))
OBJS=$(SRCS:.c=.o)

HEADERS=./includes/ 
NAME=test.exe

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS)  -o $(NAME) -I$(HEADERS) $(SRCS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS)

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all 
