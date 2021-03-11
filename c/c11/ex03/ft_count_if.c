/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:15:58 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 09:57:22 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int cnt;
	int i;

	i = -1;
	cnt = 0;
	while (++i < length)
	{
		if (f(tab[i]) != 0)
			cnt++;
	}
	return (cnt);
}
