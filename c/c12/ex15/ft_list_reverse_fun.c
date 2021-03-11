/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:42:13 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/10 13:09:09 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*list;
	void	*tmp;
	int		size;
	int		i[2];

	size = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		size++;
	}
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = i[0] - 1;
		list = begin_list;
		while (list && list->next && ++i[1] < size - 1)
		{
			tmp = list->data;
			list->data = list->next->data;
			list->next->data = tmp;
			list = list->next;
		}
	}
}
