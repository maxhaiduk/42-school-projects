/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:46:11 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/07 17:54:41 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ps means push_swap
*/

#ifndef PS_TOOLS_H
# define PS_TOOLS_H

# include "libft.h"

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

void	ps_push(t_list **from, t_list **to);
void	ps_swap(t_list *head);
void	ps_rotate(t_list **head);
void	ps_rev_rotate(t_list **head);

void	pa(t_list **a, t_list **b, int flag);
void	pb(t_list **a, t_list **b, int flag);
void	sa(t_list *a, int flag);
void	sb(t_list *b, int flag);
void	ss(t_list *a, t_list *b, int flag);
void	ra(t_list **a, int flag);
void	rb(t_list **b, int flag);
void	rr(t_list **a, t_list **b, int flag);
void	rra(t_list **a, int flag);
void	rrb(t_list **b, int flag);
void	rrr(t_list **a, t_list **b, int flag);

#endif
