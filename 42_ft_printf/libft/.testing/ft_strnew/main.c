/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/01 12:12:43 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	char *str;
	int word_len = 7;
	int i;

	str = ft_strnew(word_len);
	//str =  "hello";
	i = 0;
	while (i < word_len)
	{
		str[i] = i + 48;
		i++;
	}
	i = 0;
	while (str[i])
	{
		printf("%c\n", str[i]);
		i++;
	}
	//printf("%s\n", str); 
	
	return (0);
}
