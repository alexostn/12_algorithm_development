# The name of the final executable file
NAME = push_swap

# The compiler to be used
CC = gcc

# Compiler flags to enable warnings and treat them as errors
CFLAGS = -Wall -Wextra -Werror

# Source files that are part of the project
SRC = src/parsing.c src/sorting.c src/main.c \
	$(wildcard src/sorting_functions/*.c)

# Object files generated from the source files
OBJ = $(SRC:.c=.o)

# Directory containing header files
INCLUDE = include

# Default target to build the project
all: $(NAME)

# Rule to create the final executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Pattern rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

# Target to clean up object files
clean:
	rm -f $(OBJ)

# Target to perform a full cleanup, removing both object files and the executable
fclean: clean
	rm -f $(NAME)

# Target to recompile everything from scratch
re: fclean all

# Declare that these targets are not actual files
.PHONY: all clean fclean re
