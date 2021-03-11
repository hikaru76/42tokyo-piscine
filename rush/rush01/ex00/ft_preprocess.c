/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 17:15:07 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/28 15:49:29 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ac_cnt(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] != '\0' && av[i][1] == '\0')
			i++;
	}
	return (i);
}

void	makeboard(int board[4][4])
{
	int i;
	int j;
	int k;

	i = -1;
	k = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			board[i][j] = 0;
	}
}
