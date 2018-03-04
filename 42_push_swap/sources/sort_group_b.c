/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_group_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:50:54 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/04 16:42:03 by mhaiduk          ###   ########.fr       */
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

    top = VAL(a);
    next = VAL_NEXT(a);
    bot = VAL_N_NEXT(a);
    if (top < next && top > bot)
    {
        sb(*b);
        pa(a, b);
        pa(a, b);
        pa(a, b);
    }
    else if (top < next && next < bot)
    {
        pa(a, b);
        sb(*b);
        pa(a, b);
        sa(*b);
        pa(a, b);
        sa(*b);
    }
    else
        sort_vol3(a, b);
}

static void    sort_3_nums(t_list **a, t_list **b)
{
    int top;
    int next;
    int bot;

    top = VAL(a);
    next = VAL_NEXT(a);
    bot = VAL_N_NEXT(a);
    if (top > next && next < bot)
    {
        pa(a, b);
        sb(*b);
        pa(a, b);
        pa(a, b);
    }
    else if (top > next && top < bot)
    {
        pa(a, b);
        sb(*b);
        pa(a, b);
        sb(*b);
        pa(a, b);
    }
    else
        sort_vol2(a, b);
}

static int stack_sorted(t_list *b, int len)
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
    if (stack_sorted(*b, len))
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
    print_stacks(*a, *b);
}
