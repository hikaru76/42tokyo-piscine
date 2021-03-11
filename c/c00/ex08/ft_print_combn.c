/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 00:34:13 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/19 01:45:55 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_num(char c)
{
	write(1, &c, 1);
}

void	write_end(int a, int n)
{
	if (a < n)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	write_step(int *a, int n)
{
	int i;
	int flag;

	i = 1;
	flag = 1;
	while (i < n)
	{
		if (a[i - 1] >= a[i])
		{
			flag = 0;
		}
		i++;
	}
	if (flag)
	{
		i = 0;
		while (i < n)
		{
			write_num(a[i] + 48);
			i++;
		}
		write_end(a[0], 10 - n);
	}
}

void	ft_print_combn(int n)
{
	int i;
	int a[n];

	i = 0;
	while (i < n)
	{
		a[i] = i;
		i++;
	}
	while (a[0] <= 10 - n)
	{
		write_step(a, n);
		a[n - 1]++;
		i = n - 1;
		while (i)
		{
			if (a[i] > 9)
			{
				a[i - 1]++;
				a[i] = 0;
			}
			i--;
		}
	}
}
