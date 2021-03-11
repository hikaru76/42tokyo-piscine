/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:52:18 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 12:40:06 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
