/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:21:58 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 18:19:55 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	printqueen(int queen[10])
{
	int		i;
	char	*s;

	s = "0123456789";
	i = -1;
	while (++i < 10)
		write(1, &s[queen[i]], 1);
	write(1, "\n", 1);
}

void	changeboard_two(int board[10][10], int i, int j, int d)
{
	int k;

	if (i + j < 10)
	{
		k = -1;
		while (++k <= i + j)
			board[i + j - k][k] += d;
	}
	else
	{
		k = i + j - 10;
		while (++k < 10)
			board[i + j - k][k] += d;
	}
}

void	changeboard(int board[10][10], int i, int j, int d)
{
	int k;

	k = -1;
	while (++k < 10)
	{
		board[i][k] += d;
		board[k][j] += d;
	}
	if (i > j)
	{
		k = -1;
		while (++k < 10 - (i - j))
			board[k + (i - j)][k] += d;
	}
	else
	{
		k = -1;
		while (++k < 10 - (j - i))
			board[k][k + (j - i)] += d;
	}
	changeboard_two(board, i, j, d);
}

void	setqueen(int queen[10], int board[10][10], int i)
{
	int j;

	if (i == 10)
	{
		printqueen(queen);
		return ;
	}
	j = -1;
	while (++j < 10)
	{
		if (board[i][j] == 0)
		{
			queen[i] = j;
			changeboard(board, i, j, 1);
			setqueen(queen, board, i + 1);
			changeboard(board, i, j, -1);
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int queen[10];
	int board[10][10];
	int i;
	int j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			board[i][j] = 0;
		}
	}
	setqueen(queen, board, 0);
	return (724);
}
