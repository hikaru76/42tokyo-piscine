/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:05:25 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 00:54:14 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_judge_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_judge_wd(char c, char lc, char *charset)
{
	return (!ft_judge_sep(c, charset) && ft_judge_sep(lc, charset));
}

int		ft_cnt(char *str, char *charset)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (ft_judge_wd(str[i], str[i - 1], charset) ||
			(!ft_judge_sep(str[i], charset) && i == 0))
			cnt++;
		i++;
	}
	return (cnt);
}

int		*ft_get_len(char *str, char *charset)
{
	int	index;
	int	i;
	int	cnt;
	int	*len;

	i = 0;
	cnt = ft_cnt(str, charset);
	len = malloc(sizeof(int) * cnt);
	while (i <= cnt)
	{
		len[i] = 1;
		i++;
	}
	i = 0;
	index = 0;
	while (str[i])
	{
		if (!ft_judge_sep(str[i], charset))
			len[index]++;
		else if (i > 0 && !ft_judge_sep(str[i - 1], charset))
			index++;
		i++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		i;
	int		j;
	int		index;
	int		*len;

	dest = malloc(sizeof(char *) * (ft_cnt(str, charset) + 1));
	len = ft_get_len(str, charset);
	index = 0;
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (!ft_judge_sep(str[i], charset))
		{
			if (i == 0 || ft_judge_wd(str[i], str[i - 1], charset))
				dest[index] = malloc(sizeof(char) * len[index]);
			dest[index][j] = str[i];
			dest[index][++j] = '\0';
		}
		else if (i > 0 && !ft_judge_sep(str[i - 1], charset) && ++index)
			j = 0;
	}
	dest[ft_cnt(str, charset)] = 0;
	return (dest);
}
