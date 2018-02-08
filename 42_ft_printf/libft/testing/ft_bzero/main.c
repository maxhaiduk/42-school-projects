/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/09 11:48:38 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define N 10
#define L 10

int	main(void)
{
	char str[] = "1234567890";
	char str2[] = "1234567890";
	
	printf("Original string:\t%s\n", str);
	bzero(str, N);
	printf("C Zeroed string:\t%s", str);
	for(int i = 0; i < L; i++)
		printf("%c", str[i]);
	printf("\n");
	
	printf("Original string:\t%s\n", str2);
    ft_bzero(str2, N);
    printf("MY Zeroed string:\t");
    for(int i = 0; i < L; i++)
		printf("%c", str2[i]);
	printf("\n");

	return (0);
}
