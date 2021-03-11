/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:57:10 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/23 15:27:55 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
		return (0);
	*range = (int *)malloc((max - min) * sizeof(int));
	i = -1;
	while (++i < max - min)
		(*range)[i] = min + i;
	return (i);
}
