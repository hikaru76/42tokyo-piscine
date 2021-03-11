/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:20:44 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/22 01:11:53 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str)
{
	int i[4];

	i[0] = -1;
	i[1] = 0;
	i[3] = 0;
	i[2] = 1;
	while (str[++i[0]] == ' ' || str[i[0]] == '\n' || str[i[0]] == '\t' ||
			str[i[0]] == '\v' || str[i[0]] == '\f' || str[i[0]] == '\r')
	{
	}
	while (str[i[0]] == '-' || str[i[0]] == '+' || str[i[0]] == '0')
	{
		if (str[i[0]] == '-')
			i[2] *= -1;
		else if (str[i[0]] == '0')
			i[3] = 1;
		++i[0];
	}
	while (str[i[0]] != '\0' && str[i[0]] >= '0' && str[i[0]] <= '9')
	{
		i[1] = i[1] * 10;
		i[1] += (int)str[i[0]++] - '0';
	}
	i[1] = (i[3] && !i[1] ? 0 : i[1]);
	return (i[1] * i[2]);
}
