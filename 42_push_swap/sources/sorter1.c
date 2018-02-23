/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/23 19:57:04 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(t_list *a)
{
	t_list *b;
	int len;
	int med;

	while (a->next)
	{
		med = get_mediana(a);
		len = (int)ft_lstlen(a);
		ft_printf("Mediana is %i\n", med);
		while (len)
		{
			if (a && a->next && VAL(a) > VAL(a->next))
				ps_swap(a);
			if (b && b->next && VAL(b) < VAL(b->next))
				ps_swap(b);
			if (VAL(a) >= med)
				ps_rotate(&a);
			else
				ps_push(&a, &b);
			len--;
		}
		print_stacks(a, b);
	}
	while (b)
	{
		if (b && b->next && VAL(b) < VAL(b->next))
				ps_swap(b);
		ps_push(&b, &a);
		if (a && a->next && VAL(a) > VAL(a->next))
				ps_swap(a);
	}
	print_stacks(a, b);
}