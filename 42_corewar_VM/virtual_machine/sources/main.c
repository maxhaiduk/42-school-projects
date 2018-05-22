/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:12:55 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/05/22 17:26:38 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
		error_msg("no input parameters");
	ft_bzero(&data, sizeof(t_data));
	parse_input_params(&data, ++argv);
	init_players(&data);
	init_cursors(&data);
	init_arena(&data);
	// play_corewar(&data);
	return (0);
}