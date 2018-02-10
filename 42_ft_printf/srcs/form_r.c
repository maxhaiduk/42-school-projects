/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 10:53:49 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/10 11:12:54 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	get_hex_notation(t_fq *fq)
{
	fq->s = ft_strnew(5);
	fq->s[0] = '\\';
	if (fq->type == 'r')
		fq->s[1] = 'x';
	else
		fq->s[1] = 'X';
	fq->s = ft_strcat(fq->s, ft_itoa_base(fq->n, 16, fq->type == 'r' ? 0 : 1));
	fq->l = ft_strlen(fq->s);
}

void		form_r(t_fq *fq, va_list ap)
{
	fq->n = (char)va_arg(ap, int);
	if (ft_isprint(fq->n))
	{
		fq->s = ft_strnew(1);
		fq->s[0] = fq->n;
		fq->l = 1;
	}
	else
		get_hex_notation(fq);
	if (fq->width > fq->l)
	{
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l),
					fq->flags[ZERO] == '1' ? '0' : ' ');
	}
}
