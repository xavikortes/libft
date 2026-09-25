SRC_DIR = project
LIB = $(SRC_DIR)/libft.a
	
CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

MEMCHECK = valgrind
MEMFLAGS = --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all

all: test1 test2 test3

$(LIB): relib

relib:
	make -C ./$(SRC_DIR)

test1: relib tester_p1.out
	$(MEMCHECK) $(MEMFLAGS) ./tester_p1.out

test2: relib tester_p2.out
	$(MEMCHECK) $(MEMFLAGS) ./tester_p2.out

test3: relib tester_p3.out
	$(MEMCHECK) $(MEMFLAGS) ./tester_p3.out

tester_p1.out: $(LIB) tests/test_suite1.c
	$(CC) $(CFLAGS) -I $(SRC_DIR) tests/test_suite1.c $(SRC_DIR)/libft.a -o tester_p1.out -lbsd

tester_p2.out: $(LIB) tests/test_suite2.c
	$(CC) $(CFLAGS) -I $(SRC_DIR) tests/test_suite2.c $(LIB) -o tester_p2.out -lbsd

tester_p3.out: $(LIB) tests/test_suite3.c
	$(CC) $(CFLAGS) -I $(SRC_DIR) tests/test_suite3.c $(LIB) -o tester_p3.out -lbsd

clean:
	make clean -C ./$(SRC_DIR)

fclean: clean
	make fclean -C ./$(SRC_DIR)
	$(RM) *.out

re: fclean all

.PHONY: all clean fclean re
