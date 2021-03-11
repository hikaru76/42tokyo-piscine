/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:40:34 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 13:15:45 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strlen(char *str)
{
	unsigned int n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	unsigned int a;
	unsigned int b;

	i = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	if (a >= n && b >= n)
		return (0);
	else if (a > b)
		return (1);
	else if (a < b)
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

	int f = ft_strncmp(a,b,0);
	int g = strncmp(a,b,0);
	int h = ft_strncmp(a,d,3);
	int i = strncmp(a,d,3);
	int j = ft_strncmp(a,e,3);
	int k = strncmp(a,e,3);
	int l = ft_strncmp(b,c,3);
	int m = strncmp(b,c,3);
	printf("%d %d %d %d %d %d %d %d", f, g, h, i, j, k, l, m);
}