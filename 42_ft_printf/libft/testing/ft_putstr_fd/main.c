/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:22:19 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/04 14:12:07 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "/nfs/2017/m/mhaiduk/02_libft/libft.h"

int	main(void)
{
	char *str = "Hello, Unit!";
	char *empty = "";
	char *none = NULL;
	int fd = 1;

	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr_fd(empty, fd);
    ft_putchar_fd('\n',fd);

	ft_putstr_fd(none, fd);
    ft_putchar_fd('\n',fd);
	return (0);
}
