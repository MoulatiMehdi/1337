
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c number_to_words.c
OBJ = $(SRC:.c=.o)
NAME = rush-02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
