/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_wrap1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:38:16 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/06 17:34:57 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_tools.h"

void	pa(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
		write(1, "pa\n", 3);
	ps_push(b, a);
}

void	pb(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
		write(1, "pb\n", 3);
	ps_push(a, b);
}

void	sa(t_list *a, int flag)
{
	if (flag == 1)
		write(1, "sa\n", 3);
	ps_swap(a);
}

void	sb(t_list *b, int flag)
{
	if (flag == 1)
		write(1, "sb\n", 3);
	ps_swap(b);
}

void	ss(t_list *a, t_list *b, int flag)
{
	if (flag == 1)
		write(1, "ss\n", 3);
	ps_swap(a);
	ps_swap(b);
}
