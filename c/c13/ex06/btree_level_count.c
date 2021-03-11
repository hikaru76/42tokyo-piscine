/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:19:33 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 22:36:54 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	int	cnt;

	cnt = 0;
	if (!root)
		return (0);
	if (root->left)
		cnt = max(cnt, btree_level_count(root->left));
	if (root->right)
		cnt = max(cnt, btree_level_count(root->right));
	return (cnt + 1);
}
