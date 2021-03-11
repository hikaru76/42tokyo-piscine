/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_col_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:54:58 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/28 16:22:02 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	get_cnt_top(int board[4][4], int j)
{
	int		i;
	int		memo;
	char	cnt_top;

	i = 0;
	memo = board[j][0];
	cnt_top = 1;
	i = 0;
	while (i < 3)
	{
		if (board[j][i] < board[j][i + 1] && memo < board[j][i + 1])
		{
			memo = board[j][i + 1];
			cnt_top++;
		}
		i++;
	}
	cnt_top = (char)cnt_top + '0';
	return (cnt_top);
}

char	get_cnt_bottom(int board[4][4], int j)
{
	int		i;
	int		memo;
	char	cnt_bottom;

	cnt_bottom = 1;
	memo = board[j][3];
	i = 3;
	while (i > 0)
	{
		if (board[j][i] < board[j][i - 1] && memo < board[j][i - 1])
		{
			memo = board[j][i - 1];
			cnt_bottom++;
		}
		i--;
	}
	cnt_bottom = (char)cnt_bottom + '0';
	return (cnt_bottom);
}

int		grid_col_check(int board[4][4], char **av)
{
	int		j;
	int		count;
	char	cnt_top;
	char	cnt_bottom;

	j = -1;
	count = 0;
	while (++j < 4)
	{
		cnt_top = get_cnt_top(board, j);
		cnt_bottom = get_cnt_bottom(board, j);
		if (cnt_top == av[j][0] && cnt_bottom == av[j + 4][0])
			count++;
	}
	if (count == 4)
		return (1);
	return (0);
}
