/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/19 17:49:29 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char            *ft_itoa(long long n);

int	main(void)
{
	long long	n;
	char		*s;
	
	n = 0;
	s = ft_itoa(n);
	printf("The number is %lli\n", n);
	printf("The string is %s\n", s);

    n = 125;
    s = ft_itoa(n);
    printf("The number is %lli\n", n);
    printf("The string is %s\n", s);

    n = -125;
    s = ft_itoa(n);
    printf("The number is %lli\n", n);
    printf("The string is %s\n", s);

    n = 2147483647;
    s = ft_itoa(n);
    printf("The number is %lli\n", n);
    printf("The string is %s\n", s);

    n = -2147483648;
    s = ft_itoa(n);
    printf("The number is %lli\n", n);
    printf("The string is %s\n", s);

    n = -9223372036854775807;
    s = ft_itoa(n);
    printf("The number is %lli\n", n);
    printf("The string is %s\n", s);

    n = 9223372036854775807;
    s = ft_itoa(n);
    printf("The number is %lli\n", n);
    printf("The string is %s\n", s);


	return (0);
}
