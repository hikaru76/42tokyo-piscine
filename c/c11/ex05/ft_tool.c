/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:44:44 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 14:26:29 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		write(1, &str[n], 1);
		n++;
	}
}

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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
