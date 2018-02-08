/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:51:46 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/19 12:11:32 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_strrev(char *str);

int main(void)
{
	char str[] = "abcdef";
	printf("initial string: %s\n", str);
	ft_strrev(str);
	printf("Reversed string: %s\n", str);
	return (0);
}
