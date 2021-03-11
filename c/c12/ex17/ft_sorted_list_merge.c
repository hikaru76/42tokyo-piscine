/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:13:05 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/10 14:14:16 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	t_list	*list_before;
	t_list	*next;

	list = *begin_list;
	while (list)
	{
		list_before = *begin_list;
		while (list_before->next)
		{
			if ((*cmp)(list_before->data, list_before->next->data) > 0)
			{
				next = list_before->data;
				list_before->data = list_before->next->data;
				list_before->next->data = next;
			}
			list_before = list_before->next;
		}
		list = list->next;
	}
}

void	list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list_ptr;

	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	list_ptr = *begin_list1;
	while (list_ptr->next)
	{
		list_ptr = list_ptr->next;
	}
	list_ptr->next = begin_list2;
}

void	ft_sorted_list_merge(t_list **begin_list1,
t_list *begin_list2, int (*cmp)())
{
	list_merge(begin_list1, begin_list2);
	list_sort(begin_list1, cmp);
}
