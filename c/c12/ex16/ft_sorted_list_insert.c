/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:39:24 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/10 13:17:47 by hsakamot         ###   ########.fr       */
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

void	push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(data);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	push_back(begin_list, data);
	list_sort(begin_list, cmp);
}
