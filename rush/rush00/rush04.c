/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:51:35 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/21 01:44:34 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	draw(int x, int y, int i, int j)
{
	if (x == 1 && y == 1)
		write(1, "A", 1);
	else if ((y == 1 && i == x - 1) || (x == 1 && j == y - 1))
		write(1, "C", 1);
	else if (((i == 0 && j == 0) || (i == x - 1 && j == y - 1)))
		write(1, "A", 1);
	else if ((i == 0 && j == y - 1) || (i == x - 1 && j == 0))
		write(1, "C", 1);
	else if ((i == 0 || i == x - 1) || (j == 0 || j == y - 1))
		write(1, "B", 1);
	else
		write(1, " ", 1);
}

int		line_end(int x, int i)
{
	if (i == x - 1)
		write(1, "\n", 1);
	return (i + 1);
}

void	rush04(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			draw(x, y, i, j);
			i = line_end(x, i);
		}
		j++;
		i = 0;
	}
}
