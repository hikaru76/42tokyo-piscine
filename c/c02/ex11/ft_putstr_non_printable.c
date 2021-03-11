/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 02:50:52 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/26 11:02:57 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(unsigned char s)
{
	unsigned char a;
	unsigned char b;

	write(1, "\\", 1);
	a = s / 16;
	b = s % 16;
	if (a > 9)
		a = a - 10 + 'a';
	else
		a = a + '0';
	if (b > 9)
		b = b - 10 + 'a';
	else
		b = b + '0';
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= ' ' && str[i] <= '~'))
		{
			print_char(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
