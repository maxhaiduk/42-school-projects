/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:29:24 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/28 15:59:28 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_sign(t_fq *fq)
{
	if (fq->n < 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), '-');
	if (fq->flags[PLUS] == '1' && fq->n >= 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), '+');
}

static void compute_space(t_fq *fq)
{
		if (fq->flags[PLUS] == '0' && fq->flags[SPACE] == '1' && fq->n >= 0)
			fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), ' ');
}

static void compute_precision(t_fq *fq)
{
	if (fq->precision == 0)
	{
		fq->s = ft_strnew(0);
		fq->l = 0;
	}	
	else if (fq->precision > (int)fq->l)
		fq->s = fill_right(fq->s, fq->precision, &(fq->l), '0');
}

static void	set_sign(t_fq *fq)
{
	if (fq->n < 0)
		fq->s[0] = '-';
	if (fq->flags[PLUS] == '1' && fq->n >= 0)
		fq->s[0] = '+';
}

static void compute_width(t_fq *fq)
{
	int t;

	t = 0;
	fq->l = ft_strlen(fq->s);
	if (fq->precision > (int)fq->l)
		t = 1;
	compute_precision(fq);
	if (fq->flags[ZERO] == '0')
	{
		add_sign(fq);
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l), ' ');
	}
	else if (fq->flags[ZERO] == '1')
	{
		if (fq->flags[MINUS] == '1')
		{
			add_sign(fq);
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		}
		else
		{
			fq->s = fill_right(fq->s, fq->width, &(fq->l), t ? ' ' : ('0'));
			set_sign(fq);
		}
	}
}

static void get_value(t_fq *fq, va_list ap)
{

	if (fq->size == hh)
		fq->n = (char)(va_arg(ap, int));
	else if (fq->size == h)
		fq->n = (short)(va_arg(ap, int));
	else if (fq->size == ll)
		fq->n = va_arg(ap, long long);
	else if (fq->size == l)
		fq->n = (va_arg(ap, long));
	else if (fq->size == j)
		fq->n = (va_arg(ap, intmax_t));
	else if (fq->size == z)
		fq->n = (va_arg(ap, size_t));
	else
		fq->n = (va_arg(ap, int));
}

void	form_i_d(t_fq *fq, va_list ap)
{
	get_value(fq, ap);
	fq->s = ft_itoa_abs(fq->n);
	fq->l = ft_strlen(fq->s);
	if (fq->precision == 0 && fq->n == 0)
		compute_precision(fq);
	if (fq->precision >= (int)fq->width && fq->precision > (int)fq->l)
	{
		compute_precision(fq);
		add_sign(fq);
		compute_space(fq);
	}
	else if ((int)fq->width > fq->precision && fq->width > fq->l)
		compute_width(fq);
	else
	{
		add_sign(fq);
		compute_space(fq);
	}
}
