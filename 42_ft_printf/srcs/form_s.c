/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:44:15 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/25 12:49:39 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	form_s(t_fq *fq, va_list ap)
{
	char	*s;
	char	*t;
	size_t	len;

	s = ft_strdup(va_arg(ap, char *));
	if (!s && (fq->str_out = ft_strdup("(null)")))
		return ;
	t = s;
	if (fq->precision >= 0 && fq->precision < (int)ft_strlen(t))
	{
		s = ft_strsub(s, 0, fq->precision);
		ft_strdel(&t);
	}
	len = ft_strlen(s);
	if (fq->width > len)
	{
		t = s;
		if (fq->flags[MINUS] == '1')
			s = fill_left(s, fq->width, len, ' ');
		else
			s = fill_right(s, fq->width, len, ' ');
		ft_strdel(&t);
	}
	fq->str_out = s;
	fq->str_len = (fq->width > len) ? fq->width : len;
}
