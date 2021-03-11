/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:37:25 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/22 19:18:30 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_error_check(char *base, int base_length)
{
	int i;
	int j;

	i = -1;
	while (base[++i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0' && j < base_length)
		{
			if (base[i] == base[j++])
				return (0);
		}
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
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

int		char_in_base(char c, char *base)
{
	int i;
	int char_in;

	i = -1;
	char_in = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == c)
		{
			char_in = i;
			break ;
		}
	}
	return (char_in);
}

int		base_to_ten(char *str, char *base, int minus)
{
	int i;
	int memo;
	int ans;
	int pow;
	int base_length;

	i = 0;
	ans = 0;
	pow = 1;
	base_length = ft_strlen(base);
	while (str[i] != '\0' && char_in_base(str[i], base) >= 0)
		i++;
	memo = i;
	while (--i > 0)
		pow *= base_length;
	while (--memo > 0)
	{
		ans = ans + pow * char_in_base(str[i], base) * minus;
		pow /= base_length;
		i++;
	}
	return (ans);
}

int		ft_atoi_base(char *str, char *base)
{
	int ans;
	int str_length;
	int base_length;
	int i;
	int minus;

	str_length = ft_strlen(str);
	base_length = ft_strlen(base);
	ans = 0;
	i = 0;
	minus = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	if (base_error_check(base, base_length))
		ans = base_to_ten(str, base, minus);
	return (ans);
}
