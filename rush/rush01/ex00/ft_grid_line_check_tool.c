/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_line_check_tool.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:58:22 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/28 16:16:09 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	get_cnt_right(int x, int y, int board[4][4]);

int		line_all_check(int x, int y, int board[4][4], char **av)
{
	int		i;
	int		memo;
	char	cnt_left;
	char	cnt_right;

	i = 0;
	memo = board[0][y];
	cnt_left = 1;
	i = 0;
	while (i < 3)
	{
		if (board[i][y] < board[i + 1][y] && memo < board[i + 1][y])
		{
			memo = board[i + 1][y];
			cnt_left++;
		}
		i++;
	}
	cnt_left = (char)cnt_left + '0';
	cnt_right = get_cnt_right(x, y, board);
	if (cnt_left == av[8 + y][0] && cnt_right == av[12 + y][0])
		return (1);
	return (0);
}

int		first_line_check(int x, int board[4][4], char **av)
{
	if (av[x][0] == '1')
	{
		if (board[x][0] != 4)
			return (0);
	}
	else if (av[x][0] == '4')
	{
		if (board[x][0] != 1)
			return (0);
	}
	else if (av[x][0] == '3')
	{
		if (board[x][0] >= 3)
			return (0);
	}
	if (av[x][0] == '2')
	{
		if (board[x][0] == 4)
			return (0);
	}
	return (1);
}

int		last_line_check(int x, int board[4][4], char **av)
{
	if (av[x][3] == '1')
	{
		if (board[x][3] != 4)
			return (0);
	}
	else if (av[x][3] == '4')
	{
		if (board[x][3] != 1)
			return (0);
	}
	else if (av[x][3] == '3')
	{
		if (board[x][3] >= 3)
			return (0);
	}
	if (av[x][3] == '2')
	{
		if (board[x][3] == 4)
			return (0);
	}
	return (1);
}

int		line_each_check(int x, int y, int board[4][4])
{
	int i;

	i = -1;
	while (++i < x)
	{
		if (board[i][y] == board[x][y])
			return (0);
	}
	return (1);
}

int		col_each_check(int x, int y, int board[4][4])
{
	int i;

	i = -1;
	while (++i < y)
	{
		if (board[x][i] == board[x][y])
			return (0);
	}
	return (1);
}
