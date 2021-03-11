/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_value_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:16:04 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 14:55:54 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_char_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*catch_number(char *key)
{
	int		i;
	char	*key_cp;

	if (key[0] == '+' || key[0] == '-')
		key++;
	i = 0;
	while (key[i] != '\0' && ft_char_is_numeric(key[i]))
		i++;
	if (i != ft_strlen(key))
	{
		key_cp = (char *)malloc(sizeof(char) * (i + 1));
		ft_strncpy(key_cp, key, i);
	}
	else
		key_cp = key;
	return (key_cp);
}

int		plus_minus_key_check(char *key)
{
	int pm;
	int i;
	int	cnt;

	pm = 0;
	i = -1;
	cnt = 0;
	while (key[++i] != '\0')
	{
		if (key[i] == '+' || key[i] == '-')
			pm++;
		if (ft_char_is_numeric(key[i]))
			cnt++;
	}
	if (pm > 1 || cnt == 0)
		return (0);
	return (1);
}

int		key_error_check(char **key, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
		if (plus_minus_key_check(key[i]))
			key[i] = catch_number(key[i]);
		else
			return (0);
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (ft_strcmp(key[i], key[j]) == 0)
				return (0);
	}
	return (1);
}

int		value_error_check(char **key, char **value, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (value[i][0] == '\0')
			return (0);
	if (key_error_check(key, size))
		return (1);
	return (0);
}
