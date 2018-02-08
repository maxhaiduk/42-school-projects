/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/13 12:51:37 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../libft.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int	main(void)
{
	printf("%i\n", atoi("\t\r\n--  1"));
	printf("%i\n\n", ft_atoi("\t\r\n--  1"));

	printf("%i\n", atoi("-+1"));
	printf("%i\n\n", ft_atoi("-+1"));

    printf("%i\n", atoi("-1"));
    printf("%i\n\n", ft_atoi("-1"));

    printf("%i\n", atoi("+1"));
    printf("%i\n\n", ft_atoi("+1"));

    printf("%i\n", atoi("+-1"));
    printf("%i\n\n", ft_atoi("+-1"));

    printf("%i\n", atoi("42"));
    printf("%i\n\n", ft_atoi("42"));

    printf("%i\n", atoi("-42"));
    printf("%i\n\n", ft_atoi("-42"));

    printf("%i\n", atoi("--42"));
    printf("%i\n\n", ft_atoi("--42"));

    printf("%i\n", atoi("2147483647"));
    printf("%i\n\n", ft_atoi("2147483647"));

    printf("%i\n", atoi("-2147483648"));
    printf("%i\n\n", ft_atoi("-2147483648"));

    printf("%i\n", atoi("-a"));
    printf("%i\n\n", ft_atoi("-a"));

    printf("%i\n", atoi("2147483655"));
    printf("%i\n\n", ft_atoi("2147483655"));

	printf("%i\n", atoi("\e06050"));
    printf("%i\n\n", ft_atoi("\e06050"));

	printf("%i\n", atoi("+2798"));
    printf("%i\n\n", ft_atoi("+2798"));

	int n = ft_atoi("-2147483648");
	printf("%i\n\n", n);

	return (0);
}
