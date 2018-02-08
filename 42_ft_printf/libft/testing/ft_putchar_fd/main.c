/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/04 14:01:20 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	char c = '0';
	char empty = 0;
	int fd = 1;
	
	for (int i = 0; i < 3; i++)
		ft_putchar_fd(c, fd);
	ft_putchar_fd('\n', fd);

	ft_putchar_fd(empty, fd);
	return (0);
}
