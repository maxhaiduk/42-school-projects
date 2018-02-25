/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:46:11 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/25 13:20:35 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ps means push_swap
*/

#ifndef PS_TOOLS_H
# define PS_TOOLS_H

#include "libft.h"

void    ps_push(t_list **from, t_list **to);
void    ps_swap(t_list *head);
void    ps_rotate(t_list **head, t_list **tail);
void    ps_rev_rotate(t_list **head, t_list **tail);

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	ra(t_list **a, t_list **tail_a);
void	rb(t_list **b, t_list **tail_b);
void	rr(t_list **a, t_list **b, t_list **tail_a, t_list **tail_b);
void	rra(t_list **a, t_list **tail_a);
void	rrb(t_list **b, t_list **tail_b);
void	rrr(t_list **a, t_list **b, t_list **tail_a, t_list **tail_b);

#endif