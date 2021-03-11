/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputtwo_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:07:29 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 23:09:28 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		get_value_ten(char **key, char **value, char c, char d)
{
	if (c == '1')
	{
		select_value_ten(key, value, d);
		if (d != '0')
			return (2);
	}
	else if (c == '2')
		return (return_one(key, value, "20"));
	else if (c == '3')
		return (return_one(key, value, "30"));
	else if (c == '4')
		return (return_one(key, value, "40"));
	else if (c == '5')
		return (return_one(key, value, "50"));
	else if (c == '6')
		return (return_one(key, value, "60"));
	else if (c == '7')
		return (return_one(key, value, "70"));
	else if (c == '8')
		return (return_one(key, value, "80"));
	else if (c == '9')
		return (return_one(key, value, "90"));
	return (0);
}

void	hundred_space(char d_set[4][3], int i[3], char *c)
{
	if (d_set[i[0]][0] != '0' && d_set[i[0]][1] != '0' &&
		d_set[i[0]][2] != '0' && c[0] != '0')
		ft_putstr(" ");
	else if (d_set[i[0]][2] == '0' &&
		!(d_set[i[0]][2] == '0' && d_set[i[0]][1] == '0'))
		ft_putstr(" ");
}

void	call_hundredset(char **key, char **value, char *c)
{
	if (c[0] != '0')
	{
		get_value(key, value, c);
		ft_putstr(" ");
		get_value(key, value, "100");
	}
}

void	call_space(int i, int j)
{
	if (i == 3 && j == 2)
		ft_putstr("\n");
}

void	call_space_two(int i, int j, int k)
{
	if (i < 3 && j == 2 && k != 2)
		ft_putstr(" ");
}
