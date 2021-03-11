# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 10:47:00 by hsakamot          #+#    #+#              #
#    Updated: 2021/02/26 10:47:40 by hsakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c \
	   srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

.c.o:
		gcc -Wall -Wextra -Werror -I includes -c $< -o ${<:.c=.o}

libft.a: ${OBJS}
		ar rcs libft.a ${OBJS}

all:	libft.a

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f libft.a

re:		fclean all
