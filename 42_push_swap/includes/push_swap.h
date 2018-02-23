/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:39:56 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/23 14:44:10 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "input_error.h"
# include "ps_tools.h"

t_list	*read_array(char *str);

void	print_list(t_list *head);
void	error(char *desc);
void	memory_error(void);

#endif