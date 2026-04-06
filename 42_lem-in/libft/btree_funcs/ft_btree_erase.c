/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:58:09 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/16 17:58:11 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_erase(t_btree **root, void (*del)(void *, size_t))
{
	int a;

	if (!(*root))
		return ;
	a = *((int *)(*root)->content);
	ft_btree_erase(&((*root)->left), del);
	ft_btree_erase(&((*root)->right), del);
	if (!(*root)->right && !(*root)->left)
	{
		del((*root)->content, (*root)->content_size);
		free(*root);
		*root = NULL;
		return ;
	}
}
