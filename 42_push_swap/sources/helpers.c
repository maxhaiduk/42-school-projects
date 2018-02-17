/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:56:17 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/15 16:56:18 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	exit(ft_printf(RED "%&Error\n" RESET, 2));
}

void	memory_error(void)
{
	exit(ft_printf(RED "%&Memory allocation failed\n" RESET, 2));
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%i\n", *((int *)head->content));
		head = head->next;
	}
}
