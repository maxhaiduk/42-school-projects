/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:29:24 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/26 19:00:33 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	form_i_d(t_fq *fq, va_list ap)
{
	int		n;
	char	*s;
	size_t	len;

	n = va_arg(ap, int);
	s = ft_itoa(FT_ABS(n));

	len = ft_strlen(s);
	if (fq->precision > (int)len)
		s = fill_right(s, fq->precision, len, '0');
	if (n < 0)
	{
		len = ft_strlen(s);
		s = fill_right(s, len + 1, len, '-');
	}
	if (fq->flags[PLUS] == '1' && n > 0)
	{
		len = ft_strlen(s);
		s = fill_right(s, len + 1, len, '+');
	}
	len = ft_strlen(s);
	if (fq->width > len)
	{
        if (fq->flags[MINUS] == '1')
            s = fill_left(s, fq->width, len, ' ');
        else
            s = fill_right(s, fq->width, len, ' ');
	}
	fq->str_out = s;
	fq->str_len = ft_strlen(fq->str_out);
}
