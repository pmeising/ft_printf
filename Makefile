# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:15:22 by pmeising          #+#    #+#              #
#    Updated: 2022/05/26 13:06:48 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
CFLAGS		:= -Wall -Wextra -Werror
CC 			:= gcc
RM			:= rm -f
AR			:= ar rcs
FTPRINTF	:= ft_printf.h

SRCS	:=	ft_hex.c			\
			ft_hex_func_p.c		\
			ft_putstr.c			\
			ft_itoa.c			\
			ft_itoa_u.c			\
			ft_putchar_fd.c		\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_strlen.c			\
			ft_substr.c			\
			ft_putperc.c		\
			ft_printf.c

OBJS		:= ${SRCS:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ${FTPRINTF}
			${AR}	${NAME}	${OBJS}
			ranlib	${NAME}

%.o: %.c $(FTPRINTF)
			${CC} ${CFLAGS} -c $< -o $@


clean:
	${RM} ${OBJS} ${B_OBJS}

fclean:		clean
	${RM} $(NAME)

re:			fclean all

.PHONY:	bonus all clean fclean re