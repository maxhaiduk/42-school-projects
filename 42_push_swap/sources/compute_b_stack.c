/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_b_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:36:09 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/06 17:35:43 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		put_back_b(t_list **b, int ret_back)
{
	if (one_group_in_stack(b))
		return ;
	while (ret_back)
	{
		rrb(b, 1);
		ret_back--;
	}
}

static int		devide_b(t_list **b, t_list **a, int len, int med)
{
	int count;
	int ret_back;

	count = len % 2 ? len / 2 + 1 : len / 2;
	ret_back = 0;
	while (count)
	{
		if ((len % 2 == 0 && VAL(b) <= med) || (len % 2 == 1 && VAL(b) < med))
		{
			rb(b, 1);
			ret_back++;
		}
		else
		{
			(*b)->content_size = med;
			pa(a, b, 1);
			count--;
		}
		print_stacks(*a, *b);
	}
	return (ret_back);
}

void			compute_b_stack(t_list **a, t_list **b)
{
	int len;
	int med;
	int ret_back;

	if (!*b)
		return ;
	len = get_stack_len(*b);
	if (len <= 3)
		sort_group_b(a, b);
	len = get_stack_len(*b);
	med = get_mediana(*b, len, len % 2 ? len / 2 + 1 : len / 2);
	ret_back = devide_b(b, a, len, med);
	put_back_b(b, ret_back);
	compute_a_stack(a, b);
	compute_b_stack(a, b);
}
