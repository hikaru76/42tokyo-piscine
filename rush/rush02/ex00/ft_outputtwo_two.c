/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputtwo_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:22:33 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 23:08:51 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		decide_digit_set(char *input_num)
{
	if (ft_strlen(input_num) <= 3)
		return (3);
	else if (ft_strlen(input_num) <= 6)
		return (2);
	else if (ft_strlen(input_num) <= 9)
		return (1);
	else
		return (0);
}

int		decide_digit_set_two(char *input_num)
{
	int len;

	len = ft_strlen(input_num);
	if (len == 1 || len == 4 || len == 7 || len == 10)
		return (2);
	else if (len == 2 || len == 5 || len == 8)
		return (1);
	else
		return (0);
}

void	separate_num(char digit_set[4][3], char *input_num)
{
	int i;
	int j;
	int first[2];
	int k;

	first[0] = decide_digit_set(input_num);
	first[1] = decide_digit_set_two(input_num);
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
		{
			if (i < first[0] || (i == first[0] && j < first[1]))
				digit_set[i][j] = 'a';
			else
				digit_set[i][j] = input_num[k++];
		}
	}
}

void	get_value(char **key, char **value, char *c)
{
	int i;

	i = -1;
	while (key[++i])
	{
		if (ft_strcmp(key[i], c) == 0)
		{
			ft_putstr(value[i]);
			return ;
		}
	}
}

void	select_value_ten(char **key, char **value, char d)
{
	if (d == '0')
		get_value(key, value, "10");
	else if (d == '1')
		get_value(key, value, "11");
	else if (d == '2')
		get_value(key, value, "12");
	else if (d == '3')
		get_value(key, value, "13");
	else if (d == '4')
		get_value(key, value, "14");
	else if (d == '5')
		get_value(key, value, "15");
	else if (d == '6')
		get_value(key, value, "16");
	else if (d == '7')
		get_value(key, value, "17");
	else if (d == '8')
		get_value(key, value, "18");
	else if (d == '9')
		get_value(key, value, "19");
}
