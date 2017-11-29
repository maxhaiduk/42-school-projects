/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:53:05 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/29 13:26:47 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/input_checker.h"

/*static t_map_cont	parse_content(t_list *head)
{
	t_map_cont cont;

	cont.hashes = 0;
	cont.dots = 0;
	cont.new_lines = 0;
	cont.len = 0;
	while (head)
	{
		cont.len++;
		if (*(char *)(head->content) == '#')
			cont.hashes++;
		else if (*(char *)(head->content) == '.')
			cont.dots++;
		else if (*(char *)(head->content) == '\n')
			cont.new_lines++;
		else
		{
			ft_putstr("error\n");
			exit(1);
		}
		head = head->next;
	}
	return (cont);
	}*/

static void			check_disposition(t_list *head)
{
	int position;
	int hashes;

	position = 1;
	hashes = 0;
	while (head)
	{
		if (*(char *)(head->content) == '.' || *(char *)(head->content) == '#')
			;
		else if (*(char *)(head->content) == '\n' && position % 5 == 0)
			;
		else
		{
			ft_putstr("error\n");
			exit(1);
		}
		position++;
		if (position == 21)
			position = 0;
		head = head->next;
	}
}

void				check_content(t_map_cont cont)
{
	if (cont.hashes % 4 != 0)
	{
		ft_putstr("error\n");
		exit(1);
	}
		
}

void	check_input(t_list *head)
{
	//t_map_cont cont;

	//cont = parse_content(head);
	check_disposition(head);
	//check_content(cont);
}
