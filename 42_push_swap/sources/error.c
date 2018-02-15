/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:01:29 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/15 15:01:30 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	exit(write(2, "Error\n", 6));
}

void	memory_error(void)
{
	exit(write(2, "Memory allocation failed\n", 25));
}

void	check_type(char **arr)
{
	while (*arr)
	{
		if (!ft_is_number(*arr))
			error();
		arr++;
	}
}

void	check_values(t_list *head)
{
	while (head)
	{
		if (*((intmax_t *)head->content) > INT_MAX ||
			*((intmax_t *)head->content) < INT_MIN)
			error();
		head = head->next;
	}	
}

void	check_duplicates(t_list *head)
{
	t_list *temp;

	while (head->next)
	{
		temp = head->next;
		while (temp)
		{
			if (*((intmax_t *)temp->content) == *((intmax_t *)head->content))
				error();
			temp = temp->next;
		}
		head = head->next;
	}
}