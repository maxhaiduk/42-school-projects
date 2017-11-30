/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:15:33 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/30 09:58:31 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	show(t_list *node)
{
	ft_putchar(*(char *)(node->content));
}

int		main(int argc, char **argv)
{
	t_list *file_cont;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [filename]\n");
		return (0);
	}
	file_cont = read_file(argv[1]);
	ft_lstiter(file_cont, show);
	check_input(file_cont);
	ft_lst_erase(file_cont);
}
