/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:44:39 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/16 12:44:40 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/*
**	cmp function must returns:
**		1  - cont1 > cont2;
**		0  - cont1 == cont2;
**		-1 - cont1 < cont2;
*/

void	ft_btree_insert(t_btree *root, void *content, size_t size,
						int (*cmp)(void *cont1, void *cont2))
{
	if (!root)
		return ;
	if (cmp(content, root->content) == -1)
	{
		ft_btree_insert(root->left, content, size, cmp);
		if (!root->left)
			root->left = ft_btreenew(content, size);
	}
	else
	{
		ft_btree_insert(root->right, content, size, cmp);
		if (!root->right)
			root->right = ft_btreenew(content, size);
	}
}
