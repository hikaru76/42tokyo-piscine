/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:52:45 by dainoue           #+#    #+#             */
/*   Updated: 2021/03/08 21:53:53 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define MODE_WORD	10
#define MODE_DELIM	100

int		ft_is_delimiter(const char *charset, const char needle)
{
	if (!needle)
		return (!!1);
	while (*charset)
	{
		if (*(charset++) == needle)
			return (!!1);
	}
	return (!!0);
}

/*
** at beginning; assert(!ft_is_delimiter(*str, charset))
*/

int		ft_word_len(const char *str, const char *charset)
{
	int		i;

	i = -1;
	while (*(str + (++i)))
	{
		if (ft_is_delimiter(charset, *(str + i)))
			break ;
	}
	return (i);
}

char	*ft_strdup(const char *src, const char *finalizer)
{
	int		n;
	char	*cloned;

	n = ft_word_len(src, finalizer);
	cloned = (char*)malloc((n + 1) * sizeof(char));
	if (!cloned)
		return (NULL);
	cloned[n] = '\0';
	while (0 <= --n)
		cloned[n] = src[n];
	return (cloned);
}

int		ft_word_count(const char *str, const char *charset)
{
	int		waiting;
	int		i;
	int		word_count;

	waiting = MODE_WORD;
	i = 0;
	word_count = 0;
	while (*(str + i))
	{
		if (waiting == MODE_WORD && !ft_is_delimiter(charset, *(str + i)))
		{
			waiting = MODE_DELIM;
			word_count += 1;
		}
		else if (waiting == MODE_DELIM && ft_is_delimiter(charset, *(str + i)))
			waiting = MODE_WORD;
		i += 1;
	}
	return (word_count);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**splitted;
	int		waiting;
	int		i;
	int		p;

	word_count = ft_word_count(str, charset);
	splitted = (char**)malloc((word_count + 1) * sizeof(char*));
	waiting = MODE_WORD;
	i = -1;
	p = 0;
	while (*(str + (++i)))
	{
		if (waiting == MODE_WORD && !ft_is_delimiter(charset, *(str + i)))
		{
			waiting = MODE_DELIM;
			*(splitted + p) = ft_strdup(str + i, charset);
			p += 1;
		}
		else if (waiting == MODE_DELIM && ft_is_delimiter(charset, *(str + i)))
			waiting = MODE_WORD;
	}
	*(splitted + p) = NULL;
	return (splitted);
}
