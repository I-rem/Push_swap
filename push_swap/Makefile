NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c list_utils.c push_swap_utils.c

OBJ = $(SRC:.c=.o)

${NAME}:	${OBJS}
		${CC} ${FLAGS} -o ${NAME} ${OBJS}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(EXECUTABLE)
re: fclean all

.PHONY: all clean fclean re
	
