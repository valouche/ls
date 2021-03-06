NAME = ft_ls
#SRCS = $(wildcard *.c)
SRCS = test.c
#OBJS = $(SRCS:%.c=%.o)
OBJS = test.o
CFLAGS = -Wall -Wextra -Werror -I libft -g -ggdb
LFLAGS = -L libft -lft

all: $(NAME)

$(NAME): $(OBJS) library
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

library:
	make -C libft/

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean
