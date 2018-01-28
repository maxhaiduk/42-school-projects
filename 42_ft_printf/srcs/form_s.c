/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:44:15 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/28 15:54:25 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	form_s(t_fq *fq, va_list ap)
{
	char	*s;
	char	*t;
	size_t	len;

	s = ft_strdup(va_arg(ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	if (fq->precision >= 0 && fq->precision < (int)ft_strlen(t))
	{
		t = s;
		s = ft_strsub(s, 0, fq->precision);
		ft_strdel(&t);
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
	fq->str_len = (fq->width > len) ? fq->width : len;
}
