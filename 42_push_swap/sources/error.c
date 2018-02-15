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

int	check_type(char **arr)
{
	while (*arr)
	{
		if (!ft_is_number(*arr))
		{
			error();
			return (0);
		}
		arr++;
	}
	return (1);
}