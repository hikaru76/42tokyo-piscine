/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:08:33 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/24 00:55:22 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *a;
	int i;

	if (min >= max)
		return (NULL);
	a = (int *)malloc((max - min) * sizeof(int));
	i = -1;
	while (++i < max - min)
		a[i] = min + i;
	return (a);
}
