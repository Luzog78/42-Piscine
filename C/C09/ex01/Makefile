CC = gcc -Wall -Wextra -Werror
LIB = libft.a
SRC_DIR = ./srcs
SRC_FILES = $(SRC_DIR)/ft_putchar.c \
			$(SRC_DIR)/ft_swap.c \
			$(SRC_DIR)/ft_putstr.c \
			$(SRC_DIR)/ft_strlen.c \
			$(SRC_DIR)/ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)
H_DIR = includes
H_FILES = $(H_DIR)/ft.h

all : $(LIB)

$(LIB) : $(OBJ_FILES)
	ar -rcs $(LIB) $(OBJ_FILES) $(H_FILES)

$(OBJ_FILES) : $(SRC_FILES)
	$(CC) -c -o $@ $<

clean :
	rm -f $(OBJ_FILES)

fclean : clean
	rm -f $(LIB)

re : fclean all

.PHONY: all clean fclean re
