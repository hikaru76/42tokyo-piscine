/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:27:46 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/08 20:32:31 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_char_is_numeric(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int		ft_char_is_printable(char c)
{
	if (!(c >= ' ' && c <= '~'))
		return (0);
	return (1);
}

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
