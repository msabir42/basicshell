NAME := myshell

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

SRC_DIR := .
BUILTINS_DIR := builtins
LIBFT_DIR := libft

LIBFT := $(LIBFT_DIR)/libft.a

SRCS := \
	$(SRC_DIR)/minishell.c \
	$(BUILTINS_DIR)/builtins.c \
	$(BUILTINS_DIR)/cd.c \
	$(BUILTINS_DIR)/echo.c \
	$(BUILTINS_DIR)/pwd.c \
	$(BUILTINS_DIR)/env.c \
	$(BUILTINS_DIR)/unset.c \
	$(BUILTINS_DIR)/export.c

OBJS := $(SRCS:.c=.o)

INCLUDES := -I$(SRC_DIR) -I$(BUILTINS_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
