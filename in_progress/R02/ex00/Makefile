#Compiler
CC = cc

#Compiler Flages
CFLAGS = -Werror -Wall -Wextra

#Sources files
SRC = main.c num_to_words.c 

OBJ = $(SRC:.c=.o)

#Executable file name
TARGET=rush-02

#Rule to build the executable
all : $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

#Rule to clean everything including the executable
fclean :
	rm -f $(TARGET) *.h.gcw $(OBJ)

#Rule to rebuild the project
re : fclean all

.PHONY : fclean all re
