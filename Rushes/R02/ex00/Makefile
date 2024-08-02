# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 13:28:16 by gmassoni          #+#    #+#              #
#    Updated: 2023/07/30 22:37:55 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

HEADERS = ./include/

SRCS =	src/argparse.c \
		src/main.c \
		src/loop.c \
		src/dict/d_exists.c \
		src/dict/d_free.c \
		src/dict/d_init.c \
		src/dict/d_magic.c \
		src/dict/d_parse.c \
		src/dict/d_put.c \
		src/dict/d_sort.c \

NAME = rush-02

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a
LIBFT_SRC = libft

COUNT :=

all: ${LIBFT} ${NAME}

${LIBFT}:
	@make --no-print-directory -C ${LIBFT_SRC} all

.c.o:
	$(eval COUNT += x)
	@echo -n "\r$(NAME): / "
	@for i in $(SRCS); do \
		echo -n "▱"; \
	done
	@echo -n " / 👷 Compiling...          \r"
	@echo -n "$(NAME): / "
	@for j in $(COUNT); do \
		echo -n "▰"; \
	done
	@${CC} ${CFLAGS} -I ${HEADERS} -I ./${LIBFT_SRC}/include -c $< -o $@

${NAME}: ${OBJS}
	@echo -n " / ⛓ Linking...       \r"
	@${CC} ${CFLAGS} ${SRCS} -I ${HEADERS} -I ./${LIBFT_SRC}/include ${LIBFT_SRC}/${LIBFT} -o ${NAME}
	@echo -n "$(NAME): / "
	@for j in $(COUNT); do \
		echo -n "▰"; \
	done
	@echo " / ✅ Done!            "

clean:
	@rm -f ${OBJS}
	@make --no-print-directory -C ${LIBFT_SRC} clean

fclean: clean
	@rm -f ${NAME}
	@make --no-print-directory -C ${LIBFT_SRC} fclean
	@echo "$(NAME): Cleaned up 🧹"

re: fclean all

.PHONY: all clean fclean re
