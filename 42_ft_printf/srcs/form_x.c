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
		fq->un = (unsigned char)(va_arg(ap, int));
	else if (fq->size == h)
		fq->un = (unsigned short)(va_arg(ap, int));
	else if (fq->size == ll)
		fq->un = va_arg(ap, unsigned long long);
	else if (fq->size == l)
		fq->un = (va_arg(ap, unsigned long));
	else if (fq->size == j)
		fq->un = (uintmax_t)(va_arg(ap, intmax_t));
	else if (fq->size == z)
		fq->un = (va_arg(ap, size_t));
	else
		fq->un = (va_arg(ap, unsigned int));
}

void    form_x(t_fq *fq, va_list ap)
{
    get_value(fq, ap);
    fq->s = fq->type == 'x' ? ft_itoa_base(fq->un, 16, 0) 
                            : ft_itoa_base(fq->un, 16, 1);
    fq->l = ft_strlen(fq->s);
}