
NAME = myshell

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       gnl/get_next_line.c \
       gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

HEADERS = shell.h gnl/get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
