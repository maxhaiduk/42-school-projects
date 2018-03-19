/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:00:43 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/19 13:31:16 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_ants_qty(t_data *data, char *line)
{
	data->ant_qty = ft_atoi(line);
	if (data->ant_qty <= 0)
		ERROR_MSG("non-positive value");
	ft_strdel(&line);
}

void	check_file(t_data *data, char *line, int i)
{
	if (i && !data->ant_qty)
		ERROR_MSG("no ants quantity");
	if (!i)
		ERROR_MSG("file is empty");
}
