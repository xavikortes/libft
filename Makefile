NAME = test.out

SRCS = test.c \
	project/ft_isalpha.c \
	project/ft_isdigit.c \
	project/ft_isalnum.c \
	project/ft_isascii.c \
	project/ft_isprint.c \
	project/ft_strlen.c \
	project/ft_memset.c \
	project/ft_bzero.c \
#	project/ft_memcpy.c \
	project/ft_memmove.c \
	project/ft_strlcpy.c \
	project/ft_strlcat.c \
	project/ft_toupper.c \
	project/ft_tolower.c \
	project/ft_strchr.c \
	project/ft_strrchr.c \
	project/ft_strncmp.c \
	project/ft_memchr.c \
	project/ft_memcmp.c \
	project/ft_strnstr.c \
	project/ft_atoi.c
	

INCLUDES = project/libft.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

test: all 
	./$(NAME)	

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(SRCS)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
