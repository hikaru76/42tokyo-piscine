/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:06:18 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/03 13:19:11 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *list;

	if (begin_list == NULL)
		return ;
	while (begin_list)
	{
		free_fct(begin_list->data);
		list = begin_list;
		begin_list = begin_list->next;
		free(list);
	}
}
