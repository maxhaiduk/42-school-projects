/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/16 12:42:35 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define N 1

int	main(void)
{
	
	//char dest[] = "1234567890";
	char *dest = NULL;
	char *src = NULL;
	printf("c lib: %s\n", (char *)memcpy(dest, src, N));
	

	//char dest2[] = "1234567890";
	char *dest2 = NULL;
    char *src2 = NULL;
    printf("ftlib: %s\n", (char *)ft_memcpy(dest2, src2, N));

/*
	unsigned ltab2[11], ltab3[11];
	int j = 0;
	while (j < 11)
	{
		ltab2[j] = 0; 
		ltab3[j] = 0;
		j++;
	}
    printf("c lib: %s\n", (char *)memcpy(l, src, N));
    printf("ftlib: %s\n", (char *)ft_memcpy(dest2, src2, N));	
*/

	return (0);
}

