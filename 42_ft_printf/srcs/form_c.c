/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:46:14 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/25 15:22:02 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void form_c(t_fq *fq, va_list ap)
{
	char *s;
	char *t;

	s = ft_strnew(1);
	s[0] = (unsigned char)va_arg(ap, int);
	if (fq->width > 1)
	{
		t = s;
		if (fq->flags[MINUS] == '1')
			s = fill_left(s, fq->width, 1, ' ');
		else
			s = fill_right(s, fq->width, 1, ' ');
		ft_strdel(&t);
	}
	fq->str_out = s;
}
