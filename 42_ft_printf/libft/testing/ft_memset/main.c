/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/09 11:43:48 by mhaiduk          ###   ########.fr       */
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

#define N 11

int	main(void)
{
	// Common string;
	char src[] = "1234567890";
	char src1[] = "1234567890";
	//char *src = NULL;
	char src2[] = "1234567890";
	//char *src2 = NULL;
	printf("Origin string:\t%s\n", src);
	printf("My memset:\t%s\n", (char *)ft_memset((void *)src, '0', N));
    
	printf("Origin string:\t%s\n", src2);
	printf("C memset:\t%s\n", (char *)memset((void *)src2, '0', N));

	if (ft_strequ((char *)ft_memset((void *)src, '0', N), (char *)memset((void *)src2, '0', N)))
		printf(GRN ".....OK :)\n\n" RESET);
	else
		printf(RED "Something wrong :(\n\n" RESET); 


	/*
	Conclusion: NOT USEBLE  
	
	// Array of integer
	int numarr[] = {255};
	int numarr2[] = {255};
	printf("Origin num:\t%i\n", numarr[0]);
    printf("My memset:\t%i\n",*((int *)ft_memset((void *)&numarr, '0', 4)));
    printf("Origin string:\t%i\n", numarr2[0]);
    printf("C memset:\t%i\n", *((int *)memset((void *)&numarr2, '0', 4)));
    if (*(int *)(ft_memset((void *)numarr, 0, 4)) == *((int *)memset((void *)numarr2, 0, 4)))
        printf(GRN ".....OK :)\n\n" RESET);
    else
        printf(RED "Something wrong :(\n\n" RESET);
	*/

	/*
	Conclusion: for original memset if n - 1 > array len gcc get overflow error

	// Empty string;
	char empty[] = "";
	char empty2[] = "";
	printf("Origin string:\t%s\n", empty);
    printf("My memset:\t%s\n", (char *)ft_memset((void *)empty, '0', 5));
	printf("Origin string:\t%s\n", empty2);
    printf("C memset:\t%s\n", (char *)memset((void *)empty2, '0', 1));
    if (ft_strequ((char *)ft_memset((void *)empty, '0', 1), (char *)memset((void *)empty2, '0', 2)))
		printf(GRN ".....OK :)\n" RESET);
    else
		printf(RED "Something wrong :(\n" RESET);
	*/
	
	/*
	Conclusion: for original memset if array is NULL -> sementation fault.	
	// NULL value
	
    char *NONE = NULL;
	char *NONE2 = NULL;
    printf("Origin string:\t%s\n", NONE);
	printf("My memset:\t%s\n", (char *)ft_memset((void *)NONE, '0', 3));
	printf("Origin string:\t%s\n", NONE2);
    printf("C memset:\t%s\n", (char *)memset((void *)NONE, '0', 3));
    if (ft_strequ((char *)ft_memset((void *)NONE, '0', 3), (char *)memset((void *)NONE2, '0', 3)))
        printf(GRN ".....OK :)\n" RESET);
    else
        printf(RED "Something wrong :(\n" RESET);
	*/
	return (0);
}
