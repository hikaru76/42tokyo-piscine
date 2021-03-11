/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputtwo_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:06:21 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 23:10:06 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	hundred_put(char **key, char **value, char d_set[4][3], int i[3])
{
	char	*c;

	c = (char *)malloc(sizeof(char) * 1);
	c[0] = d_set[i[0]][i[1]];
	call_hundredset(key, value, c);
	hundred_space(d_set, i, c);
}

void	ten_put(char **key, char **value, char d_set[4][3], int i[3])
{
	char *c;

	c = (char *)malloc(sizeof(char) * 1);
	c[0] = d_set[i[0]][i[1]];
	if (d_set[i[0]][1] != 'a')
		ft_putstr(" ");
	get_value(key, value, c);
}

void	space_put_extra(char d_set[4][3], int i[3])
{
	if (!(d_set[i[0]][0] != '0'))
		ft_putstr(" ");
}

void	do_extra(char d_set[4][3], int i[3])
{
	if (i[2] < 1 && i[1] != 0 && (d_set[i[0]][0] != '0' &&
		d_set[i[0]][1] != '0' && d_set[i[0]][2] != '0'))
		space_put_extra(d_set, i);
	call_space(i[0], i[1]);
}
