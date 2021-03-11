/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:28:01 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 18:28:10 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		find(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

char	**memory(void)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (i <= g_txt)
	{
		if ((find(g_buf[i]) || g_buf[i] == '\0') &&
		(i != 0 && find(g_buf[i - 1]) == 0))
			cnt++;
		i++;
	}
	return ((char **)malloc(sizeof(char *) * (cnt + 1)));
}

void	copy(char *dest, int i, int len)
{
	int j;
	int k;

	j = 0;
	k = i;
	while (j < len)
	{
		dest[j] = g_buf[i - len + j];
		j++;
	}
	dest[j] = '\0';
}

char	**ft_split(void)
{
	int		i;
	int		j;
	int		len;
	char	**c;

	i = -1;
	j = 0;
	len = 0;
	c = memory();
	while (++i <= g_txt)
	{
		if ((find(g_buf[i]) || g_buf[i] == '\0') &&
			(len > 0 && find(g_buf[i - 1]) == 0))
		{
			c[j] = (char *)malloc(len + 1);
			copy(c[j], i, len);
			j++;
			len = 0;
		}
		else if (find(g_buf[i]) == 0)
			len++;
	}
	return (c);
}
