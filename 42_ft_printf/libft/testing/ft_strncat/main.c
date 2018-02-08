/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/08 17:50:30 by mhaiduk          ###   ########.fr       */
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

#define N 8
#define B 50

int	main(void)
{	
	char dst[B] = "Hela";
	//char dst[] = NULL;
	char *src = "1234";
	//char *src = NULL;
	printf("%s\n", strncat(dst, src, N));
	
	
	char dst2[B] = "Hela";
    //char dst[] = NULL;
    char *src2 = "1234";
    //char *src = NULL;
    printf("%s\n", ft_strncat(dst2, src2, N));
	
	return (0);
}
