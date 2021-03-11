/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cnt_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:16:00 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/28 16:16:03 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	get_cnt_right(int x, int y, int board[4][4])
{
	int cnt_right;
	int memo;
	int i;

	cnt_right = 1;
	memo = board[x][y];
	i = 3;
	while (i > 0)
	{
		if (board[i][y] < board[i - 1][y] && memo < board[i - 1][y])
		{
			memo = board[i - 1][y];
			cnt_right++;
		}
		i--;
	}
	cnt_right = (char)cnt_right + '0';
	return (cnt_right);
}
