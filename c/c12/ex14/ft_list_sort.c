/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:45:12 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/03 20:40:09 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *list_one;
	t_list *list_two;
	t_list *tmp;

	list_one = *begin_list;
	while (list_one)
	{
		list_two = *begin_list;
		while (list_two->next)
		{
			if ((cmp(list_two->data, list_two->next->data)) > 0)
			{
				tmp = list_two->data;
				list_two->data = list_two->next->data;
				list_two->next->data = tmp;
			}
			list_two = list_two->next;
		}
		list_one = list_one->next;
	}
}
