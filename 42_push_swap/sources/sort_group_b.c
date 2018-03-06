/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_group_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:50:54 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/06 11:42:24 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_vol3(t_list **a, t_list **b)
{
    sb(*b);
    pa(a, b);
    sb(*b);
    pa(a, b);
    pa(a, b);
}

static void    sort_vol2(t_list **a, t_list **b)
{
    int top;
    int next;
    int bot;

    top = VAL(b);
    next = VAL_NEXT(b);
    bot = VAL_N_NEXT(b);
    if (P_120(top, next, bot))
    {
        sb(*b);
        pa(a, b);
        pa(a, b);
        pa(a, b);
    }
    else if (P_012(top, next, bot))
    {
        pa(a, b);
        sb(*b);
        pa(a, b);
        sa(*a);
        pa(a, b);
        sa(*a);
    }
    else if (P_021(top, next, bot))
        sort_vol3(a, b);
}

static void    sort_3_nums(t_list **a, t_list **b)
{
    int top;
    int next;
    int bot;

    top = VAL(b);
    next = VAL_NEXT(b);
    bot = VAL_N_NEXT(b);
    if (P_201(top, next, bot))
    {
        pa(a, b);
        sb(*b);
        pa(a, b);
        pa(a, b);
    }
    else if (P_102(top, next, bot))
    {
        pa(a, b);
        sb(*b);
        pa(a, b);
        sa(*a);
        pa(a, b);
    }
    else
        sort_vol2(a, b);
}

static int stack_sorted_b(t_list *b, int len)
{
    len--;
    while (len)
    {
        if (*((int *)b->content) < *((int *)b->next->content))
            return (0);
        b = b->next;
        len--;
    }
    return (1);
}

void       sort_group_b(t_list **a, t_list **b)
{
	int len;

	len = get_stack_len(*b);
    if (len > 3 || len == 0)
        return ;
    if (stack_sorted_b(*b, len))
    {
        while (len)
        {
            pa(a, b);
            len--;
        }
    }
    else if (len == 2)
    {
        sb(*b);
        pa(a, b);
        pa(a, b);
    }
    else if (len == 3)
        sort_3_nums(a, b);
    sort_group_b(a, b);
}
