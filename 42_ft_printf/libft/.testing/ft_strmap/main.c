/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/01 15:49:54 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

char	invert_case(char c);

int		main(void)
{
	char str[] = "hello, UNIT!";
	char *dest;

	printf("Original string:\t%s\n", str);
	dest = ft_strmap(str, &invert_case);
	printf("Fresh string:\t\t%s\n", dest);
	return (0);
}

char	invert_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	else if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
