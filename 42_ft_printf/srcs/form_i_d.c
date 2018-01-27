/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:29:24 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/27 17:49:26 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*compute_precision(long long n, char *s, t_fq *fq)
{
	size_t 	len;

	len = ft_strlen(s);
	s = fill_right(s, fq->precision, len, '0');
	if (n < 0)
		s = fill_right(s, fq->precision + 1, fq->precision, '-');
	if (fq->flags[PLUS] == '1' && n >= 0)
		s = fill_right(s, fq->precision + 1, fq->precision, '+');
	if (fq->flags[PLUS] == '0' && fq->flags[SPACE] == '1' && n >= 0)
		s = fill_right(s, fq->precision + 1, fq->precision, ' ');
	return (s);
}

static char	*add_sign(long long n, char *s, t_fq *fq, size_t *len)
{
	if (n < 0)
		s = fill_right(s, *len + 1, *len, '-');
	if (fq->flags[PLUS] == '1' && n >= 0)
		s = fill_right(s, *len + 1, *len, '+');
	*len = ft_strlen(s);
	return (s);
}

static void	set_sign(long long n, char *s, t_fq *fq)
{
	if (n < 0)
		s[0] = '-';
	if (fq->flags[PLUS] == '1' && n >= 0)
		s[0] = '+';
}

static char	*compute_minus(long long n, char *s, t_fq *fq, size_t *len) 
{		
	if (fq->flags[MINUS] == '1')
	{
		s = add_sign(n, s, fq, len);
		s = fill_left(s, fq->width, *len, ' ');
	}
	else
	{
		s = fill_right(s, fq->width, *len, '0');
		set_sign(n, s, fq);
	}
	return (s);
}

static char	*compute_width(long long n, char *s, t_fq *fq)
{
	size_t len;

	len = ft_strlen(s);
	if (fq->precision > (int)len)
		s = fill_right(s, fq->precision, len, '0');
	len = ft_strlen(s);;
	if (fq->flags[ZERO] == '0')
	{
		s = add_sign(n, s, fq, &len);
		if (fq->flags[MINUS] == '1')
			s = fill_left(s, fq->width, len, ' ');
		else
			s = fill_right(s, fq->width, len, ' ');
	}
	else if (fq->flags[ZERO] == '1')
		s = compute_minus(n, s, fq, &len);
	return (s);
}

static char *compute_number(long long n, char *s, t_fq *fq)
{
	size_t len;

    len = ft_strlen(s);
	if (n < 0)
		s = fill_right(s, len + 1, len, '-');
	if (fq->flags[PLUS] == '1' && n >= 0)
		s = fill_right(s, len + 1, len, '+');
	len = ft_strlen(s);
	if (fq->flags[PLUS] == '0' && fq->flags[SPACE] == '1' && n >= 0)
		s = fill_right(s, len + 1, len, ' ');
	return (s);
}

static long long get_value(t_fq *fq, va_list ap)
{
	intmax_t n;

    if (fq->size == i)
        n = (va_arg(ap, int));
	else if (fq->size == hh)
		n = (char)(va_arg(ap, int));
	else if (fq->size == h)
		n = (short)(va_arg(ap, int));
	else if (fq->size == ll)
		n = va_arg(ap, long long);
	else if (fq->size == l)
		n = (va_arg(ap, long));
	else if (fq->size == j)
		n = (va_arg(ap, intmax_t));
	else if (fq->size == z)
		n = (va_arg(ap, size_t));
	return (n);
}

void	form_i_d(t_fq *fq, va_list ap)
{
	intmax_t	n;
	char		*s;
	size_t		len;

	//n = va_arg(ap, int);
	n = get_value(fq, ap);
	s = ft_itoa_abs(n);
	len = ft_strlen(s);
	if (fq->precision >= (int)fq->width && fq->precision > (int)len)
		s = compute_precision(n, s, fq);
	else if ((int)fq->width > fq->precision && fq->width > len)
		s = compute_width(n, s, fq);
	else
		 s = compute_number(n, s, fq);
	fq->str_out = s;
	fq->str_len = ft_strlen(fq->str_out);
}
