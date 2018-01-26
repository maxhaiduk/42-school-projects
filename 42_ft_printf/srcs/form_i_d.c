/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:29:24 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/26 14:57:01 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char *get_arg(t_fq *fq, va_list ap)
{
	if (fq->flags[PLUS] == '1')
		return(ft_itoa_sign(va_arg(ap, int)));
	else
		return(ft_itoa(va_arg(ap, int)));
}

void	form_i_d(t_fq *fq, va_list ap)
{
	char *s;


}
