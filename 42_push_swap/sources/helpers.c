/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:56:17 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/25 14:46:50 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *desc)
{
	if (!desc)
		exit(ft_printf(RED "%&Error\n" RESET, 2));
	else
		exit(ft_printf(RED "%&Error: %s\n" RESET, 2, desc));
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%i\n", *((int *)head->content));
		head = head->next;
	}
}

void	btree_del(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
}

int		btree_cmp(void *cont1, void *cont2)
{
	if (*((int *)cont1) < *((int *)cont2))
		return (-1);
	else if (*((int *)cont1) == *((int *)cont2))
		return (0);
	else
		return (1);
}

int		is_min(int x, int y, int z)
{
	if (x < y && x < z)
		return (1);
	else
		return (0);
}