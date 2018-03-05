/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_group_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:50:54 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/05 16:48:26 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    top_max(t_list **a, t_list **b)
{
    if (*b && (*b)->next && VAL(b) < VAL_NEXT(b))
        ss(*a, *b);
    else
        sa(*a);
    pb(a, b);
    sa(*a);
    pa(a, b);
}

static void    top_min(t_list **a, t_list **b)
{
    pb(a, b);
    sa(*a);
    pa(a, b);
}

static void    sort_3_nums(t_list **a, t_list **b)
{
    int top;
    int next;
    int bot;

    top = VAL(a);
    next = VAL_NEXT(a);
    bot = VAL_N_NEXT(a);
    if (top < next && next > bot && bot > top)
        top_min(a, b);
    else if (top > next && next < bot && bot > top)
    {
        if (*b && (*b)->next && VAL(b) < VAL_NEXT(b))
            ss(*a, *b);
        else
            sa(*a);
    }
        
    else if (top < next && next > bot && bot < top)
    {   
        top_min(a, b);
        sa(*a);
    }
    else if (top > next && next < bot && bot < top)
        top_max(a, b);
    else
    {
        top_max(a, b);
        sa(*a);
    }
}

int stack_sorted_a(t_list *a, int len)
{
    len--;
    while (len)
    {
        if (*((int *)a->content) > *((int *)a->next->content))
            return (0);
        a = a->next;
        len--;
    }
    return (1);
}

void       sort_group_a(t_list **a, t_list **b)
{
	int n;

	n = get_stack_len(*a);
    if (stack_sorted_a(*a, n))
        ;
    else if (n == 2)
        sa(*a);
    else if (n == 3)
        sort_3_nums(a, b);
}
