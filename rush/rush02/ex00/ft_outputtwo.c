/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputtwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:01:50 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 23:07:09 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	get_num_in_dic(char **key, char **value, char d_set[4][3])
{
	int		i[3];
	char	*c;

	i[0] = -1;
	c = (char *)malloc(sizeof(char) * 1);
	while (++i[0] < 4)
	{
		i[2] = 0;
		i[1] = -1;
		while (++i[1] < 3)
		{
			c[0] = d_set[i[0]][i[1]];
			if (d_set[i[0]][i[1]] == 'a')
				continue ;
			if (i[1] == 0)
				hundred_put(key, value, d_set, i);
			else if (i[1] == 1)
				i[2] = get_value_ten(key, value, c[0], d_set[i[0]][i[1] + 1]);
			else if (i[1] == 2 && i[2] != 2 && d_set[i[0]][1] != '1' &&
					d_set[i[0]][i[1]] != '0')
				ten_put(key, value, d_set, i);
			i[2] = select_thousand(key, value, i, d_set);
			do_extra(d_set, i);
		}
	}
}

void	ft_output(char **key, char **value, char *input_num)
{
	char digit_set[4][3];

	if (ft_strlen(input_num) == 1 && input_num[0] == '0')
	{
		get_value(key, value, "0");
		ft_putstr("\n");
	}
	else
	{
		separate_num(digit_set, input_num);
		get_num_in_dic(key, value, digit_set);
	}
}
