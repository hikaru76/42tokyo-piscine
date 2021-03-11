/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 01:17:00 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/26 12:11:24 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	ft_strlen(char *str)
{
	long n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

int		error_check(char *base, int length)
{
	int flag;
	int i;
	int j;

	i = -1;
	flag = 1;
	if (length == 0 || length == 1)
		flag = 0;
	while (++i < length)
	{
		j = i;
		if (base[i] == '+' || base[i] == '-')
			flag = 0;
		while (++j < length)
		{
			if (base[i] == base[j])
				flag = 0;
		}
	}
	return (flag);
}

void	write_base(long nbr, char *base, long length, int minus)
{
	long nb;

	nb = (long)nbr;
	if (minus)
	{
		nb *= -1;
		write(1, "-", 1);
		minus = 0;
	}
	if (nb >= length)
	{
		write_base(nb / length, base, length, minus);
		write_base(nb % length, base, length, minus);
	}
	else
		write(1, &base[nb], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		length;
	int		minus;

	minus = 0;
	if (nbr < 0)
		minus = 1;
	length = ft_strlen(base);
	if (error_check(base, length))
		write_base(nbr, base, length, minus);
}
