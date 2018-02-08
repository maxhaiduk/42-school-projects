/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/13 10:31:00 by mhaiduk          ###   ########.fr       */
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

#define N 5

int	main(void)
{
	/*
	char *h = "asdfdf";
	char *s = NULL;

	if (*s == '\0')
		printf("EMPTY\n");
	if (!s)
		printf("NULL\n");
	*/
	printf("c lib: %s\n", strnstr("see FF your FF return FF now FF", "FF", 25));
	printf("ftlib: %s\n", ft_strnstr("see FF your FF return FF now FF", "FF", 25));
	return (0);
}
