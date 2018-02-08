/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/09 13:39:18 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	unsigned int	n = 1;
	char			*str1 = "strong";
	char			*str2 = "str";

	if (ft_strnequ(str1, str2, n) == 1)
		printf("Strings are equal\n");
	else if (ft_strnequ(str1, str2, n) == 0)
		printf("Strings are NOT equal\n");
	return (0);
}
