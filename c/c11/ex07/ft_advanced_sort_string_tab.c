/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:16:59 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/05 13:07:52 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		j;
	int		len;
	char	*c;

	len = 0;
	if (!tab)
		return ;
	while (tab[len])
		len++;
	while (--len > 0)
	{
		j = -1;
		while (++j < len)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				c = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = c;
			}
		}
	}
}
