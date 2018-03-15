/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:39:15 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/15 15:52:02 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_type(char **arr, t_flags flags)
{
	while (*arr)
	{
		if (!ft_is_number(*arr) || !ft_strlen(*arr))
		{
			if (flags.e)
				error("incorrect type");
			else
				error(NULL);
		}
		arr++;
	}
}

void	check_values(t_list *head, t_flags flags)
{
	while (head)
	{
		if (*((intmax_t *)head->content) > INT_MAX ||
			*((intmax_t *)head->content) < INT_MIN)
		{
			if (flags.e)
				error("incorrect value");
			else
				error(NULL);
		}
		head = head->next;
	}
}

void	check_duplicates(t_list *head, t_flags flags)
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
		{
			if (flags.e)
				error("duplicates in array");
			else
				error(NULL);
		}
		head = head->next;
	}
	ft_btree_erase(&root, &btree_del);
}
