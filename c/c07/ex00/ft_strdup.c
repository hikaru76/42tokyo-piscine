/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:41:45 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/23 14:07:54 by hsakamot         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*str;
	int		i;

	src_len = ft_strlen(src);
	str = (char *)malloc(sizeof(*str) * src_len + 1);
	i = -1;
	if (!str)
		return (0);
	else
	{
		while (++i < src_len)
			str[i] = src[i];
		str[i] = '\0';
		return (str);
	}
}
