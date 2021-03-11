/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:25:17 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 12:35:43 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	output(t_map *t)
{
	int i;

	i = -1;
	while (++i < g_y)
	{
		ft_putstr(t->map[i]);
		ft_putstr("\n");
	}
}

void	fill_map(t_map *t)
{
	int i;
	int j;
	int a;
	int b;

	i = 0;
	if (g_x == 1 || g_y == 1)
	{
		t->map[0][0] = (t->map[0][0] == t->elems[0])
			? t->elems[2] : t->elems[1];
		return ;
	}
	while (i < t->ans)
	{
		j = 0;
		while (j < t->ans)
		{
			a = t->ans_y - t->ans + 1 + i;
			b = t->ans_x - t->ans + 1 + j;
			t->map[a][b] = t->elems[2];
			j++;
		}
		i++;
	}
}
