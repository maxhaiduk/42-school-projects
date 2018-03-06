/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_a_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:00:54 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/06 12:55:04 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		put_back_a(t_list **a, int ret_back)
{
	if (one_group_in_stack(a))
		return ;
	while (ret_back)
	{
		rra(a);
		ret_back--;
	}
}

static int		divide_a(t_list **a, t_list **b, int len, int med)
{
	int count;
	int ret_back;

	count = len / 2;
	ret_back = 0;
	while (count)
	{
		if ((len % 2 == 0 && VAL(a) > med) || (len % 2 == 1 && VAL(a) >= med))
		{
			if (one_group_in_stack(a) && one_group_in_stack(b) &&
				*b && (*b)->next && VAL(b) < VAL_NEXT(b))
				rr(a, b);
			else
				ra(a);
			ret_back++;
		}
		else
		{
			(*a)->content_size = med;
			pb(a, b);
			count--;
		}
		print_stacks(*a, *b);
	}
	return (ret_back);
}

void			compute_a_stack(t_list **a, t_list **b)
{
	int len;
	int med;
	int ret_back;

	len = get_stack_len(*a);
	if (len <= 3)
	{
		sort_group_a(a, b);
		return ;
	}
	med = get_mediana(*a, len, len % 2 ? len / 2 + 1 : len / 2);
	ret_back = divide_a(a, b, len, med);
	put_back_a(a, ret_back);
	compute_a_stack(a, b);
}
