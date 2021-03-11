/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:16:02 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 10:16:43 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int cnt;

	if (!str)
		return (-1);
	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int		ft_base_invalid(char *base)
{
	int i;
	int j;

	if (ft_strlen(base) <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 32 ||
			(9 <= base[i] && base[i] <= 13))
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_match(char *str, char to_find)
{
	int s;

	s = 0;
	while (str[s] != '\0')
	{
		if (str[s] == to_find)
			return (s);
		s++;
	}
	return (-1);
}
