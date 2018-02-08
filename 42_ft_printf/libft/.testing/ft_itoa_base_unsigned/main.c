/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/02 10:53:44 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../libft.h"

int	main(void)
{
	int		n;
	char	*s;
	
	n = 42;
	s = ft_itoa_base_unsigned(n, 16, 1);
	printf("The number is %i\n", n);
	printf("The string is %s\n", s);

	n = 0;
	s = ft_itoa_base_unsigned(n, 16, 0);
	printf("The number is %i\n", n);
	printf("The string is %s\n", s);

	s = ft_itoa_base_unsigned(-4294967296, 16, 1);
	printf("The string is %s\n", s);
	return (0);
}
