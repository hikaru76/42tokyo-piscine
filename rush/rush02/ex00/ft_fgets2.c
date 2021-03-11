/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgets2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:27:19 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 23:11:37 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		size(char **strs)
{
	int		i;

	i = 0;
	while (strs[i] != 0)
		i++;
	return (i);
}

void	input_key(int j, char *buf, char *str)
{
	int i;

	i = 0;
	while (str[j] != ':')
	{
		buf[i] = str[j];
		i++;
		j++;
	}
	buf[i] = '\0';
}

void	input_val(int j, char *buf, char *str)
{
	int i;

	i = 0;
	while (str[j] != '\0')
	{
		buf[i] = str[j];
		i++;
		j++;
	}
}

void	cut(char **str, char **buf_k, char **buf_v)
{
	int i;
	int j;
	int count;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		count = 0;
		while (str[i][j] == ' ')
			j++;
		while (str[i][j] != ':')
		{
			j++;
			count++;
		}
		buf_k[i] = (char *)malloc(sizeof(char) * count + 1);
		buf_v[i] = (char *)malloc(sizeof(char) * count + 1);
		input_key(j - count, buf_k[i], str[i]);
		input_val(j + 1, buf_v[i], str[i]);
		i++;
	}
}

void	ft_fgets(char **buf_k, char **buf_v, char *num)
{
	int		i;
	char	**strs;

	i = -1;
	strs = ft_split();
	buf_k = (char **)malloc(sizeof(char *) * size(strs) + 1);
	buf_v = (char **)malloc(sizeof(char *) * size(strs) + 1);
	cut(strs, buf_k, buf_v);
	while (buf_k[++i] != 0)
		trim(buf_k[i]);
	i = -1;
	while (buf_v[++i] != 0)
		trim(buf_v[i]);
	if (!value_error_check(buf_k, buf_v, i))
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	ft_output(buf_k, buf_v, num);
	free(buf_v);
	free(buf_k);
}
