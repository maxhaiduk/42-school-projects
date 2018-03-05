/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_wrap3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:45:38 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/05 14:49:13 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_tools.h"

void	rra(t_list **a)
{
	write(1, "rra\n", 4);
	ps_rev_rotate(a);
}

void	rrb(t_list **b)
{
	write(1, "rrb\n", 4);
	ps_rev_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	write(1, "rrr\n", 4);
	ps_rev_rotate(a);
	ps_rev_rotate(b);
}
