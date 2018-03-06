/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_group_a_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:57:20 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/06 16:34:32 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_vol3(t_list **a, t_list **b)
{
	ra(a);
	if (*b && (*b)-> next && VAL(b) < VAL_NEXT(b))
        ss(*a, *b);
	else
        sa(*a);
}
static void    sort_vol2(t_list **a, t_list **b)
{
    int top;
    int next;
    int bot;

    top = VAL(a);
    next = VAL_NEXT(a);
    bot = VAL_N_NEXT(a);

    if (P_120(top, next, bot))
    {   
		if (*b && (*b)-> next && VAL(b) < VAL_NEXT(b))
            ss(*a, *b);
		else
        	sa(*a);
        ra(a);
        sa(*a);
    }
    else if (P_201(top, next, bot))
		ra(a);
    else if (P_210(top, next, bot))
        sort_vol3(a, b);
}

void    sort_group_a_last(t_list **a, t_list **b)
{
    int top;
    int next;
    int bot;

    top = VAL(a);
    next = VAL_NEXT(a);
    bot = VAL_N_NEXT(a);
    if (P_021(top, next, bot))
    {
        if (*b && (*b)-> next && VAL(b) < VAL_NEXT(b))
            ss(*a, *b);
		else
			sa(*a);
		ra(a);
    }
    else if (P_102(top, next, bot))
	{
		if (*b && (*b)-> next && VAL(b) < VAL_NEXT(b))
            ss(*a, *b);
		else
        	sa(*a);
	}
    else
        sort_vol2(a, b);
}
