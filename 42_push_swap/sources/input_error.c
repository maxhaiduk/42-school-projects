/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:39:15 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/05 14:16:37 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_type(char **arr)
{
	while (*arr)
	{
		if (!ft_is_number(*arr))
			error("incorrect type");
		arr++;
	}
}

void	check_values(t_list *head)
{
	while (head)
	{
		if (*((intmax_t *)head->content) > INT_MAX ||
			*((intmax_t *)head->content) < INT_MIN)
			error("incorrect value");
		head = head->next;
	}
}

void	check_duplicates(t_list *head)
{
	t_btree *root;

	if (head)
	{
		root = ft_btreenew(head->content, head->content_size);
		head = head->next;
	}
	while (head)
	{
		if (!ft_btree_find(root, head->content, &btree_cmp))
			ft_btree_insert(root, head->content,
							head->content_size, &btree_cmp);
		else
			error("duplicates in array");
		head = head->next;
	}
	ft_btree_erase(&root, &btree_del);
}
