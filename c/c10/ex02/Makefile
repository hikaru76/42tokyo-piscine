# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 21:17:37 by hsakamot          #+#    #+#              #
#    Updated: 2021/03/09 21:17:39 by hsakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
SRCS = ft_tail.c ft_puterror.c
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

all:	${NAME}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${SRCS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean all
