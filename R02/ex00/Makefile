DICT_FILES = parse_number.c parse.c create_dictionary.c 
CVRT_FILES = num_to_words.c  convert_to_words.c three_digits_converter.c convert_extras.c

SRCS_FILES = main.c  utils.c $(addprefix dict/,$(DICT_FILES)) $(addprefix convert/,$(CVRT_FILES)) 
SRCS_DIR = ./srcs/

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_FILES)) 

OBJS = $(SRCS:.c=.o)
DEPS = ./includes/


NAME = rush-02

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(DEPS) 

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
