/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 02:30:16 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/21 20:42:11 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

int		string_check(char *str, char *to_find, int i, int a)
{
	int b;
	int j;

	b = ft_strlen(to_find);
	j = 0;
	while (++j < b && i + j < a)
	{
		if (str[i + j] != to_find[j])
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		a;
	int		b;
	int		i;
	int		flag;

	a = ft_strlen(str);
	b = ft_strlen(to_find);
	i = -1;
	flag = 0;
	if (b > a)
		return (0);
	if (to_find[0] == '\0')
		return (&str[0]);
	while (++i <= a - b)
	{
		if (str[i] == to_find[0])
			flag = string_check(str, to_find, i, a);
		if (flag)
			return (&str[i]);
	}
	return (0);
}
