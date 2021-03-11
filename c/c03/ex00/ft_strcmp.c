/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:37:12 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 13:14:45 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	if (ft_strlen(s1) > ft_strlen(s2))
		return (1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	return (0);
}

int main(void)
{
	char *a = "aaa";
	char *b = "ab";
	char *c = "ab";
	char *d = "a";
	char *e = "cdd";

	int f = ft_strcmp(a,b);
	int g = strcmp(a,b);
	int h = ft_strcmp(a,d);
	int i = strcmp(a,d);
	int j = ft_strcmp(a,e);
	int k = strcmp(a,e);
	int l = ft_strcmp(b,c);
	int m = strcmp(b,c);
	printf("%d %d %d %d %d %d %d %d", f, g, h, i, j, k, l, m);
}