# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 14:08:06 by hsakamot          #+#    #+#              #
#    Updated: 2021/03/06 01:03:10 by hsakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRCS = ft_tail.c
OBJS = ${SRCS:.c=.o}

${NAME}:
		gcc -Wall -Wextra -Werror -o ${NAME} *.c

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all
