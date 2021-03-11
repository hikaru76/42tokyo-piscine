/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:58:23 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/24 13:03:08 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char				*ft_strdup(char *src)
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_argv;
	int			i;

	i = -1;
	s_argv = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s_argv)
		return (0);
	while (++i < ac)
	{
		s_argv[i].size = ft_strlen(av[i]);
		s_argv[i].str = av[i];
		s_argv[i].copy = ft_strdup(av[i]);
	}
	s_argv[i].size = 0;
	s_argv[i].str = 0;
	s_argv[i].copy = 0;
	return (s_argv);
}
