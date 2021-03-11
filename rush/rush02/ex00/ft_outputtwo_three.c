/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputtwo_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:23:16 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 23:07:59 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	put_billion(char **key, char **val, char ds[4][3], int i[3])
{
	ft_putstr(" ");
	get_value(key, val, "1000000000");
	if (ds[i[0] + 1][0] != '0' || ds[i[0] + 1][1] != '0')
		ft_putstr(" ");
}

void	put_million(char **key, char **val, char ds[4][3], int i[3])
{
	ft_putstr(" ");
	get_value(key, val, "1000000");
	if (ds[i[0] + 1][0] != '0' || ds[i[0] + 1][1] != '0')
		ft_putstr(" ");
}

void	put_thousand(char **key, char **val, char ds[4][3], int i[3])
{
	ft_putstr(" ");
	get_value(key, val, "1000");
	if (ds[i[0] + 1][0] != '0' || ds[i[0] + 1][1] != '0')
		ft_putstr(" ");
}

int		select_thousand(char **key, char **val, int i[3], char ds[4][3])
{
	if (i[0] == 0 && i[1] == 2 && ds[i[0]][i[1]] != 'a' &&
		(ds[i[0]][0] != '0' || ds[i[0]][1] != '0' || ds[i[0]][2] != '0'))
	{
		put_billion(key, val, ds, i);
		return (2);
	}
	else if (i[0] == 1 && i[1] == 2 && ds[i[0]][i[1]] != 'a' &&
			(ds[i[0]][0] != '0' || ds[i[0]][1] != '0' || ds[i[0]][2] != '0'))
	{
		put_million(key, val, ds, i);
		return (2);
	}
	else if (i[0] == 2 && i[1] == 2 && ds[i[0]][i[1]] != 'a' &&
			(ds[i[0]][0] != '0' || ds[i[0]][1] != '0' || ds[i[0]][2] != '0'))
	{
		put_thousand(key, val, ds, i);
		return (2);
	}
	else if (i[2] == 1)
		return (1);
	else
		return (0);
}
