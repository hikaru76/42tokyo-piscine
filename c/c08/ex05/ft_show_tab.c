/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:08:30 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/25 13:36:53 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

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

void	write_num(int nb)
{
	char c;

	c = (int)'0' + nb;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		write_num(nb);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
	}
}

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

int		main(void)
{
	char *s[5] = {"", "  ", "ghihee", "jkl", "mno"};
	t_stock_str *s_av;
	s_av = ft_strs_to_tab(5, s);
	ft_show_tab(s_av);
	return (0);
}