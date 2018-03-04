/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/04 17:39:55 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_b_stack(t_list **a, t_list **b);

int		get_stack_len(t_list *a)
{
	int len;

	len = 0;
	while (a)
	{
		len++;
		if (a->next && a->content_size != a->next->content_size)
			break;
		a = a->next;
	}
	return (len);
}

void	primal_dividing(t_list **a, t_list **b)
{
	int len;
	int med;
	int count;

	len = get_stack_len(*a);
	if (len <= 3)
	{
		sort_group_a(a, b);
		return ;
	}
	count = len / 2;
	med = get_mediana(*a, len, len % 2 ? len / 2 + 1 : len / 2);
	ft_printf("Mediana is %i\n", med);
	while (count)
	{
		if ((len % 2 == 0 && VAL(a) > med) || (len % 2 == 1 && VAL(a) >= med))
			ra(a);
		else
		{
			(*a)->content_size = med;
			pb(a, b);
			count--;
		}
		print_stacks(*a, *b);
	}
	count = len % 2 ? len / 2 + 1 : len / 2;
	while (count)
	{
		rra(a);
		count--;
	}
	primal_dividing(a, b);
}

void	compute_b_stack(t_list **a, t_list **b)
{
	int len;
	int med;
	int count;

	if (!*b)
		return ;
	len = get_stack_len(*b);
	if (len <= 3)
		sort_group_b(a, b);
	len = get_stack_len(*b);
	count = len % 2 ? len / 2 + 1 : len / 2;
	med = get_mediana(*b, len, count);
	print_stacks(*a, *b);
	while (count)
	{
		if ((len % 2 == 0 && VAL(b) <= med) || (len % 2 == 1 && VAL(b) < med))
			rb(b);
		else
		{
			(*b)->content_size = med;
			pa(a, b);
			count--;
		}
	}
	count = len / 2;
	print_stacks(*a, *b);
	while (count)
	{
		rrb(b);
		count--;
	}
	print_stacks(*a, *b);
	primal_dividing(a, b);
	print_stacks(*a, *b);
	compute_b_stack(a, b);
}

void	sort_stack(t_list *a)
{
	t_list *b;

	b = NULL;
	print_stacks(a, b);
	primal_dividing(&a, &b);
	compute_b_stack(&a, &b);
	print_stacks(a, b);
}