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

void		compute_precision_unsigned(t_fq *fq)
{
	if (fq->precision == 0 && fq->un == 0)
	{
		fq->s = ft_strnew(0);
		fq->l = 0;
	}
	else if (fq->precision > (int)fq->l)
		fq->s = fill_right(fq->s, fq->precision, &(fq->l), '0');
}

void		get_value(t_fq *fq, va_list ap)
{
	if (fq->size == hh)
		fq->un = (unsigned char)(va_arg(ap, int));
	else if (fq->size == h)
		fq->un = (unsigned short)(va_arg(ap, int));
	else if (fq->size == ll)
		fq->un = va_arg(ap, unsigned long long);
	else if (fq->size == l)
		fq->un = (va_arg(ap, unsigned long));
	else if (fq->size == j)
		fq->un = (va_arg(ap, uintmax_t));
	else if (fq->size == z)
		fq->un = (va_arg(ap, size_t));
	else
		fq->un = (va_arg(ap, unsigned int));
}

void		form_x(t_fq *fq, va_list ap)
{
	get_value(fq, ap);
	fq->s = fq->type == 'x' ? ft_itoa_base_unsigned(fq->un, 16, 0)
						: ft_itoa_base_unsigned(fq->un, 16, 1);
	fq->l = ft_strlen(fq->s);
	if ((fq->precision >= (int)fq->width && fq->precision > (int)fq->l) ||
		(fq->width == 0 && fq->precision == 0 && fq->un == 0))
		compute_precision_unsigned(fq);
	else if ((int)fq->width > fq->precision && fq->width > fq->l)
		compute_width_unsigned(fq);
	else if (fq->flags[HASH] == '1' && fq->un != 0)
		add_prefix(fq);
}
