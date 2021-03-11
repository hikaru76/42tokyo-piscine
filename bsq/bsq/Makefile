# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 06:24:35 by dainoue           #+#    #+#              #
#    Updated: 2021/03/08 10:03:13 by hsakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

${NAME}:
		gcc -Wall -Wextra -Werror -o ${NAME} *.c

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all
