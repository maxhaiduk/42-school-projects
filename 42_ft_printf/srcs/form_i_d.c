/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:29:24 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/27 11:20:30 by mhaiduk          ###   ########.fr       */
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

static char	*compute_width(long long n, char *s, t_fq *fq)
{
	size_t len;

	len = ft_strlen(s);
	if (fq->precision > (int)len)
		s = compute_precision(n, s, fq);
	else if (fq->flags[ZERO] == '0')
	{
		if (n < 0)
			s = fill_right(s, len + 1, len, '-');
		if (fq->flags[PLUS] == '1' && n >= 0)
			s = fill_right(s, len + 1, len, '+');
		len = ft_strlen(s);
		if (fq->flags[MINUS] == '1')
			s = fill_left(s, fq->width, len, ' ');
		else
			s = fill_right(s, fq->width, len, ' ');
	}
	else if (fq->flags[ZERO] == '1')
	{
		len = ft_strlen(s);
		if (fq->flags[MINUS] == '0')
		{
			s = fill_right(s, fq->width, len, '0');
			if (n < 0)
				s[0] = '-';
			if (fq->flags[PLUS] == '1' && n >= 0)
				s[0] = '+';		
		}
		else
		{
			if (n < 0)
				s = fill_right(s, len + 1, len, '-');
			if (fq->flags[PLUS] == '1' && n >= 0)
				s = fill_right(s, len + 1, len, '+');
			len = ft_strlen(s);
			s = fill_left(s, fq->width, len, ' ');
		}
	}
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

void	form_i_d(t_fq *fq, va_list ap)
{
	long long	n;
	char	*s;
	size_t	len;

	n = va_arg(ap, int);
	s = ft_itoa(FT_ABS(n));
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
