# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 14:08:06 by hsakamot          #+#    #+#              #
#    Updated: 2021/03/01 14:51:14 by hsakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_display_file.c
OBJS = ${SRCS:.c=.o}

ft_display_file:
		gcc -Wall -Wextra -Werror ${SRCS} -o ft_display_file

all:	ft_display_file

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ft_display_file

re:		fclean all