/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:56:22 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 21:56:25 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_base_invalid(char *base);
int		ft_match(char *str, char to_find);

char	*ft_atos(char *nbr, char *base_from)
{
	int		i;
	char	*valid_nbr;

	i = 0;
	valid_nbr = (char *)malloc(sizeof(char) * 33);
	if (!valid_nbr)
		return (0);
	*valid_nbr = 0;
	while (ft_match(base_from, nbr[i]) >= 0)
	{
		valid_nbr[i] = nbr[i];
		i++;
	}
	valid_nbr[i] = '\0';
	return (valid_nbr);
}

void	ft_rev_char_tab(char *tab, int size)
{
	int		i;
	char	tmp[size];

	i = 0;
	while (i < size)
	{
		tmp[i] = *(tab + i);
		i++;
	}
	while (i-- > 0)
	{
		*tab = tmp[i];
		tab++;
	}
}

long	ft_base_to_long(char *nbr, char *base_from)
{
	long	num;
	int		nbase;
	int		i;

	num = 0;
	nbase = ft_strlen(base_from);
	i = 0;
	while (nbr[i])
		num = num * nbase + ft_match(base_from, nbr[i++]);
	return (num);
}

char	*ft_long_to_base(int num, char *base_to)
{
	char	*dest;
	int		i;
	int		num_edit;

	dest = (char *)malloc(sizeof(char) * 33);
	if (!dest)
		return (0);
	*dest = 0;
	i = 0;
	num_edit = num;
	if (num < 0)
		num_edit *= -1;
	while (num_edit >= 0)
	{
		dest[i++] = base_to[num_edit % ft_strlen(base_to)];
		num_edit /= ft_strlen(base_to);
		if (num_edit == 0)
			break ;
	}
	if (num < 0)
		dest[i++] = '-';
	dest[i] = '\0';
	ft_rev_char_tab(dest, i);
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*valid_nbr;
	long	tmp;
	int		minus;
	char	*dest;

	if (ft_base_invalid(base_from) || ft_base_invalid(base_to) || !nbr)
		return (0);
	minus = 1;
	while (*nbr == ' ' || (9 <= *nbr && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			minus *= -1;
		nbr++;
	}
	valid_nbr = ft_atos(nbr, base_from);
	tmp = ft_base_to_long(valid_nbr, base_from);
	free(valid_nbr);
	tmp *= minus;
	dest = ft_long_to_base(tmp, base_to);
	return (dest);
}
