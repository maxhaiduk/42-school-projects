/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/09 13:35:23 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../libft.h"

int	main(void)
{
	char *str1 = "111";
	char *str2 = "1111";

	if (ft_strequ(str1, str2) == 1)
		printf("Strings are equal\n");
	else if (ft_strequ(str1, str2) == 0)
		printf("Strings are NOT equal\n");
	return (0);
}
