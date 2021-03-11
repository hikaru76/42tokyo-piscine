/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:12:36 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/28 23:21:18 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		error_check_two(char **av);
int		error_check(int ac, char **av);
char	**ft_split(char *str, char *charset);
void	ft_putstr(char *str);
void	write_num(int nb);
void	output_board(int board[4][4]);
int		ac_cnt(char **av);
void	makeboard(int board[4][4]);
int		grid_line_check(int x, int y, int board[4][4], char **av);
int		grid_col_check(int board[4][4], char **av);
int		g_found;

void	end(int board[4][4])
{
	output_board(board);
	g_found = 1;
}

void	dfs(int x, int y, int board[4][4], char **av)
{
	int i;

	if (g_found)
		return ;
	if (!grid_line_check(x, y, board, av))
		return ;
	if (x == 3 && y == 3 && grid_col_check(board, av))
		end(board);
	i = 0;
	while (++i <= 4)
	{
		if (x < 4)
		{
			board[x + 1][y] = i;
			dfs(x + 1, y, board, av);
			board[x + 1][y] = 0;
		}
		else if (y < 3)
		{
			board[0][y + 1] = i;
			dfs(0, y + 1, board, av);
			board[0][y + 1] = 0;
		}
	}
}

void	solve(int board[4][4], char **av)
{
	int i;

	i = 0;
	while (++i <= 4)
	{
		board[0][0] = i;
		dfs(0, 0, board, av);
		board[0][0] = 0;
	}
	return ;
}

int		main(int argc, char **argv)
{
	int		ac;
	char	**av;
	int		board[4][4];

	g_found = 0;
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	av = ft_split(argv[1], "\" ");
	ac = ac_cnt(av);
	if (!error_check(ac, av))
	{
		ft_putstr("Error\n");
		return (0);
	}
	makeboard(board);
	solve(board, av);
	if (g_found == 0)
		ft_putstr("Error\n");
	exit(0);
	return (0);
}
