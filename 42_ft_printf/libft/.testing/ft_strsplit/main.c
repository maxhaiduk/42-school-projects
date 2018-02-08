/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/15 11:34:58 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../libft.h"

int	main(void)
{
	char *str = "a   b     c d e";
	char **cont;

	cont = ft_strsplit(str, ' ');
	if (cont)
	{
		while (*cont != 0)
		{
			printf("%s\n", *cont);
			cont++;
		}
	}
	else
		printf("Nothing to print\n");
	return (0);
}
