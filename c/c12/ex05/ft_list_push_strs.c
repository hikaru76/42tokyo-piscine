/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:26:44 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/03 13:10:53 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	if (size < 1)
		return (0);
	list = ft_create_elem(strs[0]);
	i = 0;
	while (++i < size)
	{
		tmp = ft_create_elem(strs[i]);
		tmp->next = list;
		list = tmp;
	}
	return (list);
}
