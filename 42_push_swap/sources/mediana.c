/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:28:43 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/05 14:46:53 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	btree_step(t_btree *root, int *gate, int *med)
{
	if (!root)
		return ;
	btree_step(root->left, gate, med);
	(*gate)--;
	if (!(*gate))
		*med = *((int *)root->content);
	btree_step(root->right, gate, med);
}

int			get_mediana(t_list *head, int len, int steps)
{
	t_btree	*root;
	int		s;
	int		med;

	root = NULL;
	s = steps;
	while (len)
	{
		if (!root)
			root = ft_btreenew(head->content, sizeof(int));
		else
			ft_btree_insert(root, head->content, sizeof(int), &btree_cmp);
		head = head->next;
		len--;
	}
	btree_step(root, &s, &med);
	ft_btree_erase(&root, &btree_del);
	return (med);
}
