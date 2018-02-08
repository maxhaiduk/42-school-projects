/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/14 14:38:23 by mhaiduk          ###   ########.fr       */
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

#define N 50
#define B 7

int	main(void)
{	
	size_t max = 6;
	
	char dst[N] = "abc";
	printf("dst string: %s\tlen: %lu\n", dst, strlen(dst));
	//char dst[] = NULL;
	char *src = "abc";
	printf("src string: %s\t\t\tlen: %lu\ndst_size: %lu\n", src, strlen(src), max);

	//char *src = NULL;
	printf("c lib: %lu : %s\n", strlcat(dst, src, max), dst);
	

	char dst2[N] = "abc";
	int i = 0;
	while (i < 6)
	{
		dst[4 + i] = 'z';
		dst2[4 + i] = 'z';
		++i;
	}
    //char dst[] = NULL;
    //char *src2 = "the cake is a lie !\0I'm hidden lol\r\n";
    //char *src = NULL;
	//printf("%s\n", dst2);
    printf("ftlib: %lu : %s\n", ft_strlcat(dst2, src, max), dst2);
	
	return (0);
}
