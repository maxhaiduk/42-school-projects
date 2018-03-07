/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:39:56 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/07 12:36:27 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "input_error.h"
# include "ps_tools.h"

# define VAL(x) *((int *)(*x)->content)
# define VAL_NEXT(x) *((int *)(*x)->next->content)
# define VAL_N_NEXT(x) *((int *)(*x)->next->next->content)

# define P_012(top, next, bot) (top < next && next < bot && bot > top) ? 1 : 0
# define P_021(top, next, bot) (top < next && next > bot && bot > top) ? 1 : 0
# define P_102(top, next, bot) (top > next && next < bot && bot > top) ? 1 : 0
# define P_120(top, next, bot) (top < next && next > bot && bot < top) ? 1 : 0
# define P_201(top, next, bot) (top > next && next < bot && bot < top) ? 1 : 0
# define P_210(top, next, bot) (top > next && next > bot && bot < top) ? 1 : 0

t_list	*parse_string(char *str);
t_list	*parse_args(char **args);

/*
** helpers.c
*/
void	error(char *desc);
void	print_list(t_list *head);
void	btree_del(void *content, size_t content_size);
int		btree_cmp(void *cont1, void *cont2);
int		is_min(int x, int y, int z);

void	print_stacks(t_list *a, t_list *b);
void 	sort_stack(t_list **a, t_list **b);
void	compute_a_stack(t_list **a, t_list **b);
void	compute_b_stack(t_list **a, t_list **b);
int 	get_mediana(t_list *head, int len, int steps);
int		get_stack_len(t_list *a);
int     one_group_in_stack(t_list **a);
void    sort_group_a(t_list **a, t_list **b);
void	sort_group_a_last(t_list **a, t_list **b);
void    sort_group_b(t_list **a, t_list **b);
int     stack_sorted_a(t_list *a, int len);
#endif