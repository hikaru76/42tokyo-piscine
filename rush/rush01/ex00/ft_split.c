/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:05:25 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/27 15:10:22 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		char_in_base(char c, char *base)
{
	int i;
	int char_in;

	i = -1;
	char_in = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == c)
		{
			char_in = i;
			break ;
		}
	}
	return (char_in);
}

char	*ft_strlcpy(char *dest, char *src, int size)
{
	int i;
	int n;

	i = 0;
	n = size - 1;
	if (size == 0)
		return ("");
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		get_s_length(char *str, char *charset)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (str[++i] != '\0')
	{
		if (char_in_base(str[i], charset) > 0)
			cnt++;
	}
	return (i - cnt);
}

char	**ft_cut(char *str, char *charset, int strlen, char **s)
{
	int i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = get_s_length(str, charset);
	while (--strlen >= 0)
	{
		if (char_in_base(str[i[0]], charset) >= 0)
		{
			if (i[0] > 0)
			{
				s[i[1]] = (char *)malloc(sizeof(char) * (i[0] + 1));
				ft_strlcpy(s[i[1]++], str, i[0] + 1);
			}
			str += i[0] + 1;
			i[0] = -1;
		}
		i[0]++;
	}
	if (i[0] > 0)
	{
		s[i[1]] = (char *)malloc(sizeof(char) * (i[0] + 1));
		ft_strlcpy(s[i[1]], str, i[0] + 1);
	}
	return (s);
}

char	**ft_split(char *str, char *charset)
{
	int		slen;
	int		strlen;
	char	**s;

	if (!str)
		return (NULL);
	strlen = 1;
	while (str[strlen] != '\0')
		strlen++;
	slen = get_s_length(str, charset);
	if (!(s = (char **)malloc(sizeof(char *) * (slen + 1))))
		return (NULL);
	s = ft_cut(str, charset, strlen, s);
	return (s);
}
