# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 14:08:06 by hsakamot          #+#    #+#              #
#    Updated: 2021/03/02 13:26:34 by hsakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
SRCS = ft_cat.c
OBJS = ${SRCS:.c=.o}

${NAME}:
		gcc -Wall -Wextra -Werror ${SRCS} -o ${NAME}

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all
