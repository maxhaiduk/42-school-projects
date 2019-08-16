/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_preorder_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:55:23 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/16 16:56:00 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_inorder_print(t_btree *root, void (*p)(void *))
{
	if (!root)
		return ;
	ft_btree_inorder_print(root->left, p);
	p(root->content);
	ft_btree_inorder_print(root->right, p);
}
