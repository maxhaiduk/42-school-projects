/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/04 12:06:40 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	int *nptr = NULL;

	ft_putnbr(0);
	ft_putchar('\n');

    ft_putnbr(125);
    ft_putchar('\n');

    ft_putnbr(-357);
    ft_putchar('\n');

    ft_putnbr(2147483647);
    ft_putchar('\n');

    ft_putnbr(-2147483648);
    ft_putchar('\n');

    ft_putnbr(*nptr);
    ft_putchar('\n');

	return (0);
}
