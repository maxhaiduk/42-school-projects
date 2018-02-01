/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:27:16 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/01 17:27:21 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	get_value(t_fq *fq, va_list ap)
{
	if (fq->size == hh)
		fq->n = (unsigned char)(va_arg(ap, int));
	else if (fq->size == h)
		fq->n = (unsigned short)(va_arg(ap, int));
	else if (fq->size == ll)
		fq->n = va_arg(ap, unsigned long long);
	else if (fq->size == l)
		fq->n = (va_arg(ap, unsigned long));
	else if (fq->size == j)
		fq->n = (va_arg(ap, uintmax_t));
	else if (fq->size == z)
		fq->n = (va_arg(ap, size_t));
	else
		fq->n = (va_arg(ap, unsigned int));
}

void    form_x(t_fq *fq, va_list ap)
{
    get_value(fq, ap);
    fq->s = fq->type == 'x' ? ft_itoa_base(fq->n, 16, 0) 
                            : ft_itoa_base(fq->n, 16, 1);
	fq->l = ft_strlen(fq->s);
	if ((fq->precision >= (int)fq->width && fq->precision > (int)fq->l) ||
		(fq->width == 0 && fq->precision == 0 && fq->n == 0))
		compute_precision(fq);	
    else if ((int)fq->width > fq->precision && fq->width > fq->l)
		compute_width_unsigned(fq);
	else if (fq->flags[HASH] == '1' && fq->n != 0)
		add_prefix(fq);
}