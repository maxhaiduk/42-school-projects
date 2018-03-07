/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:08:25 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/07 11:23:55 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_list *a, t_list *b)
{
	ft_printf(UNDERLINE BOLD GREEN "\nStack A: " RESET);
	if (!a)
		ft_printf(RED "empty" RESET);
	while (a)
	{
		ft_printf("%i ", *((int *)a->content));
		a = a->next;	}
	write(1, "\n", 1);
	ft_printf(UNDERLINE BOLD BLUE "\nStack B: " RESET);
	if (!b)
		ft_printf(RED "empty" RESET);
	while (b)
	{
		ft_printf("%i ", *((int *)b->content));
		b = b->next;
	}
	write(1, "\n\n", 2);
}
