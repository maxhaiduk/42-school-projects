/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/09 18:27:35 by mhaiduk          ###   ########.fr       */
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
#define D 5
#define S 1

int	main(void)
{	
	char dest[] = "1234567890";
	memmove(&dest[D], &dest[S], N);
	printf("\n%s\n", dest);
	printf("%s\n", (char *)memmove(&dest[D], &dest[S], N));
	

	char dest2[] = "1234567890";
	memmove(&dest2[D], &dest2[S], N);
	printf("\n%s\n", dest2);
    printf("%s\n", (char *)memmove(&dest2[D], &dest2[S], N));

	if (ft_strequ(dest, dest2))
		printf(GRN ".......OK :)" RESET);
	else
		printf(RED ".......KO :(" RESET);
	return (0);

}
