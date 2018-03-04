/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_b_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:36:09 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/04 19:24:56 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     put_back_b(t_list **b, int ret_back)
{
    if (one_group_in_stack(b))
        return ;
	while (ret_back)
	{
		rrb(b);
		ret_back--;
	}
}

void	compute_b_stack(t_list **a, t_list **b)
{
	int len;
	int med;
	int count;
    int ret_back;

    print_stacks(*a, *b);
	if (!*b)
		return ;
	len = get_stack_len(*b);
	if (len <= 3)
		sort_group_b(a, b);
	len = get_stack_len(*b);
	count = len % 2 ? len / 2 + 1 : len / 2;
	med = get_mediana(*b, len, count);
	print_stacks(*a, *b);
    ret_back = 0;
	while (count)
	{
		if ((len % 2 == 0 && VAL(b) <= med) || (len % 2 == 1 && VAL(b) < med))
        {
			rb(b);
            ret_back++;
        }
		else
		{
			(*b)->content_size = med;
			pa(a, b);
			count--;
		}
        print_stacks(*a, *b);
	}
    put_back_b(b, ret_back);
	print_stacks(*a, *b);
	compute_a_stack(a, b);
	print_stacks(*a, *b);
	compute_b_stack(a, b);
}