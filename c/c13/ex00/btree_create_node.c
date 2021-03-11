/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:40:26 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 20:49:51 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *btree;

	btree = (t_btree *)malloc(sizeof(t_btree));
	if (btree)
	{
		btree->right = 0;
		btree->left = 0;
		btree->item = item;
	}
	return (btree);
}
