/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:31:02 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 00:56:01 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int		ft_str_totallen(char **str, int size, char *sep)
{
	int n;
	int len;

	n = -1;
	len = 0;
	while (++n < size)
	{
		len += ft_strlen(str[n]);
	}
	return (len + ft_strlen(sep) * (size - 1) + 1);
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;

	if (size == 0)
	{
		s = malloc(sizeof(char));
		*s = 0;
		return (s);
	}
	if (!(s = malloc(sizeof(char) * ft_str_totallen(strs, size, sep))))
		return (NULL);
	*s = 0;
	i = -1;
	while (++i < size)
	{
		ft_strcat(s, strs[i]);
		if (i < size - 1)
			ft_strcat(s, sep);
	}
	return (s);
}
