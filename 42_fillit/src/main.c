/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:15:33 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/12/04 10:57:09 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	show(t_list *node)
{
	ft_putchar(*(char *)(node->content));
}

int		main(int argc, char **argv)
{
	t_list	*file_cont;
	int		tet_num;
	t_tetro	*tetro_list;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit target_file");
		return (0);
	}
	file_cont = read_file(argv[1]);
	tet_num = check_input(file_cont);
	tetro_list = fetch_coords(file_cont, tet_num); 
	solve_problem(tetro_list, tet_num);
	ft_lst_erase(file_cont);
	free_list_tetro(&tetro_list);
	return (0);
}
