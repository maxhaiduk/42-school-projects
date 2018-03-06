/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_wrap3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:45:38 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/06 17:32:09 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_tools.h"

void	rra(t_list **a, int flag)
{
	if (flag == 1)
		write(1, "rra\n", 4);
	ps_rev_rotate(a);
}

void	rrb(t_list **b, int flag)
{
	if (flag == 1)
		write(1, "rrb\n", 4);
	ps_rev_rotate(b);
}

void	rrr(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
		write(1, "rrr\n", 4);
	ps_rev_rotate(a);
	ps_rev_rotate(b);
}
