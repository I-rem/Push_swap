CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = push_swap

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
