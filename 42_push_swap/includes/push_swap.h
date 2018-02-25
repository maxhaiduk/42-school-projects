/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:39:56 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/25 12:51:36 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "input_error.h"
# include "ps_tools.h"

# define VAL(x) *((int *)x->content)
# define IS(x) 	(x && x->next) ? 1 : 0

t_list	*read_array(char *str);

/*
** helpers.c
*/
void	error(char *desc);
void	print_list(t_list *head);
void	btree_del(void *content, size_t content_size);
int		btree_cmp(void *cont1, void *cont2);

void	print_stacks(t_list *a, t_list *b);
void 	sort_stack(t_list *a);
int 	get_mediana(t_list *head);
#endif