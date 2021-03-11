/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:29:53 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/10 16:08:05 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		btree_level_count(t_btree *root)
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

void	apply(t_btree *root, int current_level, int *levels,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		first_item;

	first_item = 1;
	if (levels[current_level] == 1)
		first_item = 0;
	else
		levels[current_level] = 1;
	applyf(root->left, current_level, first_item);
	if (root->left)
		apply(root->left, current_level + 1, levels, applyf);
	if (root->right)
		apply(root->right, current_level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		count;
	int		*levels;
	int		i;

	if (root == 0)
		return ;
	count = btree_level_count(root);
	if (!(levels = (int*)malloc(sizeof(int) * count)))
		return ;
	i = 0;
	while (i < count)
		levels[i++] = 0;
	apply(root, 0, levels, applyf);
}
