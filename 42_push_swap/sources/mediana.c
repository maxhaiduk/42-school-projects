/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:28:43 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/23 19:33:59 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void btree_step(t_btree *root, int *gate, int *med)
{
	int n;

	if (!root)
		return ;
	n = VAL(root);
	btree_step(root->left, gate, med);
	(*gate)--;
	if (!(*gate))
		*med = n;
	btree_step(root->right, gate, med);
}

int get_mediana(t_list *head)
{
	t_btree	*root;
	int		len;
	int		med;

	root = NULL;
	len = (int)ft_lstlen(head);
	while (head)
	{
		if (!root)
			root = ft_btreenew(head->content, sizeof(int));
		else
			ft_btree_insert(root, head->content, sizeof(int), &btree_cmp);
		head = head->next;
	}
	len = len / 2 + 1;
	btree_step(root, &len, &med);
	ft_btree_erase(&root, &btree_del);
	return (med);
}