/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/01 13:28:32 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

void	invert_case(char *c);

int		main(void)
{
	char str[] = "hello, UNIT!";

	printf("Original string: %s\n", str);
	ft_striter(str, &invert_case);
	printf("Modified string: %s\n", str);
	return (0);
}

void	invert_case(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
	else if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}
