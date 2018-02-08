/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/04 14:31:59 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	//int *nptr = NULL;
	int fd = 1; 

	ft_putnbr_fd(0, fd);
	ft_putchar('\n');

    ft_putnbr_fd(125, fd);
    ft_putchar('\n');

    ft_putnbr_fd(-357, fd);
    ft_putchar('\n');

    ft_putnbr_fd(2147483647, fd);
    ft_putchar('\n');

    ft_putnbr_fd(-2147483648,fd);
    ft_putchar('\n');

	// ft_putnbr(*nptr);
    //ft_putchar('\n');

	return (0);
}
