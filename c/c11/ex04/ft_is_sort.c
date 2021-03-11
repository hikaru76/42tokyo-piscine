/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:19:38 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 10:15:23 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int flag_one;
	int flag_two;

	i = -1;
	flag_one = 0;
	flag_two = 0;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			flag_one++;
		if (f(tab[i], tab[i + 1]) <= 0)
			flag_two++;
	}
	if (flag_one == length - 1 || flag_two == length - 1 || length == 0)
		return (1);
	return (0);
}
