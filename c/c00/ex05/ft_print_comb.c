/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:40:55 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/19 09:59:01 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writethree(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

char	whilefor(char ch)
{
	if (ch == '9')
	{
		ch = '0';
	}
	else
	{
		ch++;
	}
	return (ch);
}

void	writenumber(char a, char b, char c)
{
	if (a < b && b < c)
	{
		writethree(a, b, c);
		if (!(a == '7' && b == '8' && c == '9'))
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	ft_print_comb(void)
{
	char n[3];

	n[0] = '0';
	n[1] = '0';
	n[2] = '0';
	while (n[0] <= '9')
	{
		while (n[1] <= '9')
		{
			while (n[2] <= '9')
			{
				writenumber(n[0], n[1], n[2]);
				n[2]++;
			}
			n[1]++;
			n[2] = '0';
		}
		n[0]++;
		n[1] = '0';
	}
}
