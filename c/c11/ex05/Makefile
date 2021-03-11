# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 14:08:06 by hsakamot          #+#    #+#              #
#    Updated: 2021/03/01 23:03:44 by hsakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = ft_doop.c ft_putnbr.c ft_tool.c
OBJS = ${SRCS:.c=.o}

${NAME}:
		gcc -Wall -Wextra -Werror -o ${NAME} *.c

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all
