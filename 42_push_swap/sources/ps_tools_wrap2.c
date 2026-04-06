/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_wrap2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:38:34 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/06 17:29:11 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_tools.h"

void	ra(t_list **a, int flag)
{
	if (flag == 1)
		write(1, "ra\n", 3);
	ps_rotate(a);
}

void	rb(t_list **b, int flag)
{
	if (flag == 1)
		write(1, "rb\n", 3);
	ps_rotate(b);
}

void	rr(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
		write(1, "rr\n", 3);
	ps_rotate(a);
	ps_rotate(b);
}
