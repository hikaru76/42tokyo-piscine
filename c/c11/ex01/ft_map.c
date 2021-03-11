/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:08:10 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 14:59:10 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *rt;

	if (!(rt = (int *)malloc(length * sizeof(int))))
		return (NULL);
	i = -1;
	*rt = 0;
	while (++i < length)
		rt[i] = f(tab[i]);
	return (rt);
}
