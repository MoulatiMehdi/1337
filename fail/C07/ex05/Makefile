#Compiler
CC = cc

#Compiler Flags
	CFLAGS = -Wall - Wextra -
	Werror

#Source Files
		SRC = $(wildcard *.c)

#Object Files
					OBJ = $(SRC
							:.c =.o)

#Executable
						TARGET = program

#Rules
									all : $(TARGET)

											$(TARGET)
	: $(OBJ) $(CC) $(CFLAGS) - o $ @$ ^

	%.o : %.c $(CC) $(CFLAGS) - c $ < -o $ @

										clean : rm -
			f $(OBJ)

				fclean : clean rm -
							f $(TARGET)

								re : fclean all

										.PHONY : all clean fclean re
