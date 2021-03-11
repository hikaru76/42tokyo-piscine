/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:52:18 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/21 16:59:26 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int a;
	int b;
	int i;

	a = ft_strlen(dest);
	b = ft_strlen(src);
	i = -1;
	while (++i < b)
	{
		dest[a + i] = src[i];
	}
	dest[a + b] = '\0';
	return (dest);
}
