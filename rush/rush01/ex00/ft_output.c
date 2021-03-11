/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:56:14 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/27 19:02:17 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int n;

	n = -1;
	while (str[++n] != '\0')
		write(1, &str[n], 1);
}

void	write_num(int nb)
{
	char c;

	c = (int)'0' + nb;
	write(1, &c, 1);
}

void	output_board(int board[4][4])
{
	int i;
	int j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			write_num(board[i][j]);
			if (i < 3)
				ft_putstr(" ");
		}
		ft_putstr("\n");
	}
}
