/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dainoue <dainoue@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:25:06 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 12:31:01 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

void	init_numap(int numap[g_y][g_x], t_map *t)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_y)
	{
		j = -1;
		while (++j < g_x)
		{
			if (t->map[i][j] == t->elems[1])
				numap[i][j] = 0;
			else
				numap[i][j] = -1;
		}
	}
}

void	sub_main(t_map *t)
{
	int	numap[g_y][g_x];

	init_numap(numap, t);
	if (!(g_x == 1 || g_y == 1))
		dp(numap, t);
	fill_map(t);
	output(t);
}

int		main(int argc, char **argv)
{
	t_map	*t;
	char	buf[100000];
	int		i;

	t = malloc(sizeof(t_map) * 1);
	init(t);
	i = 0;
	if (argc == 1)
	{
		std_input_map(buf);
		buf_to_map(t, buf);
	}
	else
		while (++i < argc)
			if (input_map(argv[i], buf))
				buf_to_map(t, buf);
	free(t);
	return (0);
}
