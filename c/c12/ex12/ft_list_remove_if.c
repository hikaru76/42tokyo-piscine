/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:34:23 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/03 19:12:41 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
							void (*free_fct)(void *))
{
	t_list	*list;
	t_list	*tmp;

	list = *begin_list;
	while (list && list->next)
	{
		if (cmp(list->next->data, data_ref) == 0)
		{
			tmp = list->next;
			list->next = list->next->next;
			free_fct(tmp->data);
			free(tmp);
		}
		list = list->next;
	}
	list = *begin_list;
	if (list && cmp(list->data, data_ref) == 0)
	{
		*begin_list = list->next;
		free_fct(list->data);
		free(list);
	}
}
