/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:11:34 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 09:53:47 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_any(char **tab, int (*f)(char*))
{
	int i;

	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]) != 0)
			return (1);
	}
	return (0);
}
