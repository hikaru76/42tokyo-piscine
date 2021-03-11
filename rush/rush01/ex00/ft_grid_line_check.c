/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_line_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 17:39:29 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/28 16:10:01 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		line_all_check(int x, int y, int board[4][4], char **av);
int		first_line_check(int x, int board[4][4], char **av);
int		last_line_check(int x, int board[4][4], char **av);
int		line_each_check(int x, int y, int board[4][4]);
int		col_each_check(int x, int y, int board[4][4]);

int		call_check(int x, int y, int board[4][4], char **av)
{
	int		flag;

	flag = 1;
	if (y == 3)
	{
		if (!last_line_check(x, board, av))
			flag = 0;
	}
	if (y >= 1 && y <= 3)
	{
		if (!col_each_check(x, y, board))
			flag = 0;
	}
	return (flag);
}

int		grid_line_check(int x, int y, int board[4][4], char **av)
{
	if (x == 3)
	{
		if (!line_all_check(x, y, board, av))
			return (0);
	}
	if (x >= 1 && x <= 3)
	{
		if (!line_each_check(x, y, board))
			return (0);
	}
	if (y == 0)
	{
		if (!first_line_check(x, board, av))
			return (0);
	}
	return (call_check(x, y, board, av));
}
