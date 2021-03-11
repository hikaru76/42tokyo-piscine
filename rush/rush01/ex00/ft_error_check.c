/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:54:04 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/27 17:11:14 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**face to face error check
**if 1 then reverse side must be 2, 3, 4
**if 2 then reverse side must be 1, 2, 3
**if 3 then reverse side must be 1, 2
**if 4 then reverse side must be 1
**if passed return 1 in order to do main process
*/

int		error_check_two(char **av)
{
	int i;
	int j;

	i = 0;
	while (i < 16)
	{
		j = -1;
		while (++j < 4)
		{
			if (av[i + j][0] == '1')
				if (av[i + j + 4][0] == '1')
					return (0);
			if (av[i + j][0] == '2')
				if (av[i + j + 4][0] == '4')
					return (0);
			if (av[i + j][0] == '3')
				if (av[i + j + 4][0] == '3' || av[i + j + 4][0] == '4')
					return (0);
			if (av[i + j][0] == '4')
				if (av[i + j + 4][0] != '1')
					return (0);
		}
		i += 8;
	}
	return (1);
}

/*
**error_check:input error check
**if no '1' in line then return 0
**if input bigger than 4 or smaller than 1 then return 0
**then error_check_two
*/

int		error_check(int ac, char **av)
{
	int i;
	int j;

	if (ac != 16)
		return (0);
	i = -1;
	while (++i < 16)
	{
		j = 0;
		while (av[i][j] != 0)
			j++;
		if (j != 1)
			return (0);
		if (av[i][0] < '1' || av[i][0] > '4')
			return (0);
	}
	i = 0;
	while (i < 12)
	{
		if (av[0 + i][0] != '1' && av[1 + i][0] != '1' &&
			av[2 + i][0] != '1' && av[3 + i][0] != '1')
			return (0);
		i += 4;
	}
	return (error_check_two(av));
}
