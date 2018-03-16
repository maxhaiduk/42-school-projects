/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:28:21 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/15 13:12:26 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_data	data;

	data = read_data();
	find_path(data);
	free_matrix(data.adj);
	ft_lstdel(&(data.rooms), &delete_room);

	// while (1)
	// 	;	
	return (0);
}