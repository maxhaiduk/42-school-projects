/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_group_a_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:57:20 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/11 16:07:27 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_vol3(t_list **a, t_list **b)
{
	ra(a, 1);
	if (*b && (*b)->next && VAL(b) < VAL_NEXT(b))
		ss(*a, *b, 1);
	else
		sa(*a, 1);
}

static void	sort_vol2(t_list **a, t_list **b)
{
	int top;
	int next;
	int bot;

	top = VAL(a);
	next = VAL_NEXT(a);
	bot = VAL_N_NEXT(a);
	if (P_120(top, next, bot))
		rra(a, 1);
	else if (P_201(top, next, bot))
		ra(a, 1);
	else if (P_210(top, next, bot))
		sort_vol3(a, b);
}

void		sort_group_a_last(t_list **a, t_list **b)
{
	int top;
	int next;
	int bot;

	top = VAL(a);
	next = VAL_NEXT(a);
	bot = VAL_N_NEXT(a);
	if (P_021(top, next, bot))
	{
		if (*b && (*b)->next && VAL(b) < VAL_NEXT(b))
			ss(*a, *b, 1);
		else
			sa(*a, 1);
		ra(a, 1);
	}
	else if (P_102(top, next, bot))
	{
		if (*b && (*b)->next && VAL(b) < VAL_NEXT(b))
			ss(*a, *b, 1);
		else
			sa(*a, 1);
	}
	else
		sort_vol2(a, b);
}
