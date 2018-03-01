/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:08:25 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/01 17:09:34 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_list *a, t_list *b)
{
	int diff;

	diff = ft_lstlen(a) - ft_lstlen(b);
	ft_printf("\n");
	while (diff)
	{
		if (diff > 0)
		{
			ft_printf("\t|%3i |\n", *((int *)a->content));
			a = a->next;
			diff--;
		}
		else if (diff < 0)
		{
			ft_printf("\t    \t\t|%3i |\n", *((int *)b->content));
			b = b->next;
			diff++;
		}
	}
	while (a && b)
	{
		ft_printf("\t|%3i |\t\t|%3i |\n", *((int *)a->content),
										*((int *)b->content));
		a = a->next;
		b = b->next;
	}
	ft_printf("---------------------------------------\n");
	ft_printf("        stack A         stack B\n");
}