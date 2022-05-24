# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:15:22 by pmeising          #+#    #+#              #
#    Updated: 2022/05/23 15:06:00 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a
CFLAGS		:=	-Wall -Wextra -Werror
CC 			:=	gcc
RM			:=	rm -f
AR			:=	ar rcs
FTPRINTF	:=	ft_printf.h

SRCS	:=	ft_putstr.c			\
			ft_printf.c			\
			ft_itoa.c			\
			ft_putchar_fd.c		\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_strlen.c			\
			ft_substr.c			\

OBJS		:= ${SRCS:.c=.o}

.PHONY:	bonus	all	clean	fclean	re

all:		${NAME}

$(NAME):	${OBJS}
			${AR}	${NAME}	${OBJS}
			ranlib	${NAME}

%.o: %.c $(FTPRINTF)
			${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} ${B_OBJS}

fclean:		clean
	${RM} $(NAME)

re:			fclean all