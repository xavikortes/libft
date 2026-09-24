NAME = test.out

SRC_DIR = project

SRCS = $(SRC_DIR)/ft_*.c

OBJS = test.c $(SRCS)
	
CC = cc
CFLAGS = -Wall -Werror -Wextra -Wno-error=format-overflow

RM = rm -f

all: $(NAME)

test: all 
	./$(NAME)	

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lbsd

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
