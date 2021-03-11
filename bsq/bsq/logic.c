/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:27:04 by dainoue           #+#    #+#             */
/*   Updated: 2021/03/09 01:40:59 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		get_min2(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int		get_min3(int numap[g_y][g_x], int x, int y)
{
	int	a;
	int	b;

	a = get_min2(numap[y - 1][x], numap[y][x - 1]);
	b = get_min2(a, numap[y - 1][x - 1]);
	return (b);
}

void	set_numap(int numap[g_y][g_x])
{
	int i;

	i = -1;
	while (++i < g_x)
	{
		if (numap[0][i] == -1)
			numap[0][i] = 1;
		else
			numap[0][i] = 0;
	}
	i = 0;
	while (++i < g_y)
	{
		if (numap[i][0] == -1)
			numap[i][0] = 1;
		else
			numap[i][0] = 0;
	}
}

void	dp(int numap[g_y][g_x], t_map *t)
{
	int n[4];

	set_numap(numap);
	n[0] = 0;
	while (++n[0] < g_y)
	{
		n[1] = 0;
		while (++n[1] < g_x)
		{
			n[2] = get_min2(numap[n[0] - 1][n[1]], numap[n[0] - 1][n[1] - 1]);
			n[3] = get_min2(n[2], numap[n[0]][n[1] - 1]);
			if (numap[n[0]][n[1]] != 0)
				numap[n[0]][n[1]] = n[3] + 1;
			if (t->ans < numap[n[0]][n[1]])
			{
				t->ans = numap[n[0]][n[1]];
				t->ans_x = n[1];
				t->ans_y = n[0];
			}
		}
	}
}
