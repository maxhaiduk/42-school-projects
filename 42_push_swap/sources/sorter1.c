/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/05 13:47:14 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int      one_group_in_stack(t_list **a)
{
    t_list *temp;

    temp = *a;
    if (!temp)
        return (1);
    while (temp->next)
    {
        if (temp->content_size != temp->next->content_size)
            return (0);
        temp = temp->next;    
    }
    return (1);
}

void	sort_stack(t_list **a, t_list **b)
{
	print_stacks(*a, *b);
	compute_a_stack(a, b);
	compute_b_stack(a, b);
	print_stacks(*a, *b);
}