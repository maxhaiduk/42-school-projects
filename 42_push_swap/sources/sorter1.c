/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/01 14:15:50 by mhaiduk          ###   ########.fr       */
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

	len = (int)ft_lstlen(*a);
	len = len % 2 ? len / 2 + 1 : len / 2;
	med = get_mediana(*a, len);
	ft_printf("Mediana is %i\n", med);
	while (len)
	{
		(*a)->content_size = med;
		ft_printf("NODE: content: %i\ncontent size: %i\n",*((int *)(*a)->content), (*a)->content_size = med);
		if (VAL(a) > med)
			ra(a, tail_a);
		else
		{
			pb(a, b);
			len--;
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