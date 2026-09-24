SRC_DIR = project

SRCS = $(SRC_DIR)/ft_*.c
	
CC = cc
CFLAGS = -Wall -Werror -Wextra -Wno-error=format-overflow

RM = rm -f

all: p1 p2 lst

p1: p1.out
	./p1.out

p2: p2.out
	./p2.out

lst: lst.out
	./lst.out	

p1.out: $(SRCS)
	$(CC) $(CFLAGS) -o p1.out test_part1.c $(SRCS) -lbsd

p2.out: $(SRCS)
	$(CC) $(CFLAGS) -o p2.out test_part2.c $(SRCS) -lbsd

lst.out: $(SRCS)
	$(CC) $(CFLAGS) -o lst.out test_lst.c $(SRCS) -lbsd

clean:

fclean: clean
	$(RM) p1.out p2.out lst.out

re: fclean all

.PHONY: all clean fclean re
