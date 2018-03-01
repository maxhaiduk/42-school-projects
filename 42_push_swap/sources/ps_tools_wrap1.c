/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_wrap1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:38:16 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/01 14:36:28 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	write(1, "pa\n", 3);
	ps_push(b, a);
}

void	pb(t_list **a, t_list **b)
{
	write(1, "pb\n", 3);
	ps_push(a, b);
}

void	sa(t_list *a)
{
	write(1, "sa\n", 3);
	ps_swap(a);
}

void	sb(t_list *b)
{
	write(1, "sb\n", 3);
	ps_swap(b);
}

void	ss(t_list *a, t_list *b)
{
	write(1, "ss\n", 3);
	ps_swap(a);
	ps_swap(b);
}

void	ra(t_list **a)
{
	write(1, "ra\n", 3);
	ps_rotate(a);
}

void	rb(t_list **b)
{
	write(1, "rb\n", 3);
	ps_rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	write(1, "rr\n", 3);
	ps_rotate(a);
	ps_rotate(b);
}

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