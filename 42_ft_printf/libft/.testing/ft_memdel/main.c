/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/10/27 16:02:09 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	int *num;
	char *c;
	void *empty = NULL;

	num = malloc(sizeof(int));
	*num = 5;
	printf("num = %i\n", *num);
	ft_memdel((void **)&num);
	if (!num)
		printf("Memory was fried\n\n");

	c = (char *)malloc(sizeof(char));
	*c = 'c';
	printf("char = %c\n", *c);
    ft_memdel((void **)&c);
    if (!c)
        printf("Memory was fried\n\n");

	ft_memdel(&empty);

	return (0);
}
