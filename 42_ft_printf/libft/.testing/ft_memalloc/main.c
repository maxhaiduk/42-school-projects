/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/10/27 12:20:00 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	int *num;
	char *c;

	printf("Sizeof(0) = %lu\n\n", sizeof(0));

	num = (int *)(ft_memalloc(sizeof(int)));
	//*num = 5;
	if (num)
		printf("num = %i\nSizeof(int) = %lu\n\n", *num, sizeof(int));
	else
		printf("Memory was not allocated\n");

	c = (char *)(ft_memalloc(sizeof(char)));
	//*c = *c + 49;
	if (c)
        printf("c = %i\nSizeof(char) = %lu\n", *c, sizeof(char));
    else
		printf("Memory was not allocated\n");
	
	return (0);
}
