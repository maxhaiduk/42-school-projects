/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/01 14:01:10 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *get_tail(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head); 
}


void	primal_dividing(t_list **a, t_list **b, t_list **tail_a)
{
	int len;
	int med;
	int x;
	int y;
	int z;

	len = (int)ft_lstlen(*a);
	len = len % 2 ? len / 2 + 1 : len / 2;
	med = get_mediana(*a, len);
	ft_printf("Mediana is %i\n", med);
	while (len)
	{
		if (*a && (*a)->next)
		{
			x = VAL(a);
			y = VAL(tail_a);
			z = VAL_NEXT(a);
			if (x <= med && is_min(x, y, z))
				;
			else if (z <= med && is_min(z, y, x))
				sa(*a);
			else if (y <= med && is_min(y, x, z))
				rra(a, tail_a);
			else
				ra(a, tail_a);
			if (VAL(a) <= med)
			{
				pb(a, b);
				len--;
			}
		}
		print_stacks(*a, *b);
	}
}


void	sort_stack(t_list *a)
{
	t_list *tail_a;
	t_list *b;
	//t_list *tail_b;
	//int len;

	//len = ft_lstlen(a);
	//ft_printf("len is %i\n", len);
	b = NULL;
	tail_a = get_tail(a);
	print_stacks(a, b);
	primal_dividing(&a, &b, &tail_a);
}