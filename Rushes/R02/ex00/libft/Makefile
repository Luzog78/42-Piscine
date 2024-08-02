# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:20:18 by kiroussa          #+#    #+#              #
#    Updated: 2023/07/30 22:38:02 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

# find -type f -name "*.c" | sed "s/\.\///g" | xargs -Iname echo "`printf '\t\t\t'`" name "\\"
SRCS	=	src/io/get_next_line.c \
			 src/io/ft_putstr.c \
			 src/io/ft_putstr_fd.c \
			 src/io/ft_putchar_fd.c \
			 src/io/ft_putchar.c \
			 src/string/ft_isdigit.c \
			 src/string/ft_strdup_range.c \
			 src/string/ft_append.c \
			 src/string/ft_ratoi_ull.c \
			 src/string/ft_isspace.c \
			 src/string/ft_strncpy.c \
			 src/string/ft_strdup.c \
			 src/string/ft_ratoi_ll.c \
			 src/string/ft_isalpha.c \
			 src/string/ft_strlcpy.c \
			 src/string/ft_strlen.c \
			 src/string/ft_strlcat.c \
			 src/math/ft_abs.c \

INCLUDES = include

OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
COPTS	= -I ./${INCLUDES} -fPIC

AR		= ar
ARFLAGS	= rcs

RM		= rm
RMFLAGS	= -f

COUNT	:=

all:	${NAME}

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
	@${CC} ${CFLAGS} ${COPTS} -c $< -o $@

${NAME}:	${OBJS}
	@echo -n " / ⛓ Linking...       \r"
	@${AR} ${ARFLAGS} ${NAME} ${OBJS}
	@echo -n "$(NAME): / "
	@for j in $(COUNT); do \
		echo -n "▰"; \
	done
	@echo " / ✅ Done!            "

clean:
	@${RM} ${RMFLAGS} ${OBJS}

fclean:	clean
	@${RM} ${RMFLAGS} ${NAME}
	@echo "$(NAME): Cleaned up 🧹"

re:	fclean all

.PHONY:	all norm fclean clean re
