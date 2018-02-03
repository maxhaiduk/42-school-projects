/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:31:46 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/03 15:31:47 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void form_p(t_fq *fq, va_list ap)
{
    fq->un = (va_arg(ap, uintmax_t));
    fq->s = ft_itoa_base_unsigned(fq->un, 16, 0);
    fq->l = ft_strlen(fq->s);
    if ((fq->precision >= (int)fq->width && fq->precision > (int)fq->l) ||
		(fq->width == 0 && fq->precision == 0 && fq->un == 0))
		{
			compute_precision_unsigned(fq);
			add_prefix(fq);
		}
	else if ((int)fq->width > fq->precision && fq->width > fq->l)
		compute_width_unsigned(fq);
    else
        add_prefix(fq);
}