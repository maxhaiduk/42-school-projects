/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_09_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:21:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/06/01 13:38:03 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_data *data, t_process *process)
{
	short offset;

	if (!process->carry)
		return ;
	offset = get_short_number(VALUE(process, 0));
	offset %= IDX_MOD;
	compute_pc(data, process, offset);
}
