/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:39:56 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/05 14:08:09 by mhaiduk          ###   ########.fr       */
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

t_list	*read_array(char *str);

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
void    sort_group_b(t_list **a, t_list **b);
int     stack_sorted_a(t_list *a, int len);
#endif