/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:15:20 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/01 12:36:57 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	char *c;
	int i;
	int len;

	len = 5;
	c = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		c[i] = i + 97;
		i++;
	}
	printf("str = %s\n", c);
    ft_strdel(&c);
    if (!c)
        printf("Memory was fried\n");

	return (0);
}
