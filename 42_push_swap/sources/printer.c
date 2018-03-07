/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:08:25 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/07 17:40:49 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	ft_printf(GREEN BOLD UNDERLINE "\nStack A: " RESET);
	if (!a)
		ft_printf(RED "empty" RESET);
	while (a)
	{
		ft_printf("%i ", *((int *)a->content));
		a = a->next;
	}
	ft_printf(BLUE BOLD UNDERLINE "\n\nStack B: " RESET);
	if (!b)
		ft_printf(RED "empty" RESET);
	while (b)
	{
		ft_printf("%i ", *((int *)b->content));
		b = b->next;
	}
	write(1, "\n\n", 2);
}

void	print_help(void)
{
	ft_printf("Usage: ./checker [flags][array]\n\n");
	ft_printf("[flags]:\n-v - visualization of stacks\n");
	ft_printf("-s - view statistics about operations\n\n");
	ft_printf("[array]:\n");
	ft_printf("one string like: \"3 2 1\"\n");
	ft_printf("or\n");
	ft_printf("few arguments: 3 2 1\n");
	exit(1);
}
