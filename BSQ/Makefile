# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 13:28:16 by gmassoni          #+#    #+#              #
#    Updated: 2023/08/02 20:34:14 by ysabik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	main.c \
		src/grid.c \
		src/pos.c \
		src/solution.c \
		src/free.c \
		src/utils/ft_atoi.c \
		src/utils/ft_puterr.c \
		src/utils/ft_putstr.c \
		src/utils/ft_strlen.c \
		src/read_file.c \
		src/loop.c

NAME = bsq

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
