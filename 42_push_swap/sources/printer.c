/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:08:25 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/05 12:47:15 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_stacks(t_list *a, t_list *b)
// {
// 	int diff;

// 	diff = ft_lstlen(a) - ft_lstlen(b);
// 	ft_printf("%&\n", 2);
// 	while (diff)
// 	{
// 		if (diff > 0)
// 		{
// 			ft_printf("%&\t|%3i :%3i|\n", 2, *((int *)a->content), a->content_size);
// 			a = a->next;
// 			diff--;
// 		}
// 		else if (diff < 0)
// 		{
// 			ft_printf("%&\t    \t\t|%3i :%3i|\n", 2, *((int *)b->content), b->content_size);
// 			b = b->next;
// 			diff++;
// 		}
// 	}
// 	while (a && b)
// 	{
// 		ft_printf("%&\t|%3i :%3i|\t|%3i :%3i|\n", 2, *((int *)a->content), a->content_size,
// 										*((int *)b->content), b->content_size);
// 		a = a->next;
// 		b = b->next;
// 	}
// 	ft_printf("%&---------------------------------------\n", 2);
// 	ft_printf("%&        stack A         stack B\n", 2);
// }

void print_stacks(t_list *a, t_list *b)
{
	int diff;

	diff = ft_lstlen(a) - ft_lstlen(b);
	ft_printf("%&\n", 2);
	while (diff)
	{
		if (diff > 0)
		{
			ft_printf("\t|%3i :%3i|\n", *((int *)a->content), a->content_size);
			a = a->next;
			diff--;
		}
		else if (diff < 0)
		{
			ft_printf("\t    \t\t|%3i :%3i|\n", *((int *)b->content), b->content_size);
			b = b->next;
			diff++;
		}
	}
	while (a && b)
	{
		ft_printf("\t|%3i :%3i|\t|%3i :%3i|\n", *((int *)a->content), a->content_size,
										*((int *)b->content), b->content_size);
		a = a->next;
		b = b->next;
	}
	ft_printf("---------------------------------------\n");
	ft_printf("        stack A         stack B\n");
}