NAME1 = _test1.out
NAME2 = _test2.out
NAME3 = _test3.out

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
MEMCHECK = valgrind
MEMFLAGS = --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all

LIB_DIR = ./project
LIBS = \
	$(LIB_DIR)/libft.a

TEST_DIR = ./tests
TEST1 = $(TEST_DIR)/test_suite1.c
TEST2 = $(TEST_DIR)/test_suite2.c
TEST3 = $(TEST_DIR)/test_suite3.c

all: test1 test2 test3

test1: $(NAME1)
	./$(NAME1)

test2: $(NAME2)
	./$(NAME2)

test3: $(NAME3)
	./$(NAME3)

$(NAME1): $(LIBS)
	$(CC) $(CFLAGS) $(TEST1) $(LIBS) -o $(NAME1) -lbsd

$(NAME2): $(LIBS)
	$(CC) $(CFLAGS) $(TEST2) $(LIBS) -o $(NAME2) -lbsd

$(NAME3): $(LIBS)
	$(CC) $(CFLAGS) $(TEST3) $(LIBS) -o $(NAME3) -lbsd

$(LIBS):
	$(MAKE) -C $(LIB_DIR)

memcheck: $(NAME)
	$(MEMCHECK) $(MEMFLAGS) ./$(NAME1)
	$(MEMCHECK) $(MEMFLAGS) ./$(NAME2)
	$(MEMCHECK) $(MEMFLAGS) ./$(NAME3)

clean:
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(NAME1) $(NAME2) $(NAME3)

re: fclean all

.PHONY: all test1 test2 test3 memcheck clean fclean re
