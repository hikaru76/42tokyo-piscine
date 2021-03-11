/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:37:06 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 14:28:03 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft.h"

void	ft_calc(int a, int b, char c)
{
	if (c == '+')
		ft_putnbr(a + b);
	else if (c == '-')
		ft_putnbr(a - b);
	else if (c == '*')
		ft_putnbr(a * b);
	else if (c == '/')
		ft_putnbr(a / b);
	else
		ft_putnbr(a % b);
	ft_putstr("\n");
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc != 4)
		return (0);
	if ((argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' &&
		argv[2][0] != '/' && argv[2][0] != '%') || ft_strlen(argv[2]) != 1)
	{
		ft_putstr("0\n");
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (b == 0 && argv[2][0] == '/')
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	else if (b == 0 && argv[2][0] == '%')
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	ft_calc(a, b, argv[2][0]);
	return (0);
}
