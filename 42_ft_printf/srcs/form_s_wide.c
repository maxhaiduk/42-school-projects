/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_s_wide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:26:00 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/07 15:26:02 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t  wstr_len(wchar_t *wstr)
{
    size_t len;

    len = 0;
    while (wstr[len])
        len++;
    return (len);
}

void    get_wstr(t_fq *fq)
{
    size_t  i;
    size_t  len;
    char    *temp;
    char    *w_temp;

    len = wstr_len(fq->p);
    i = 0;
    fq->s = ft_strnew(0);
    while (i < len)
    {
        temp = fq->s;
        w_temp = encode_symbol(fq->p[i]);
        fq->s = ft_strjoin(fq->s, w_temp);
        free(w_temp);
        free(temp);
        i++;
    }
    fq->l = ft_strlen(fq->s);
}

void    form_s_wide(t_fq *fq, va_list ap)
{
    char	*t;

    fq->p = va_arg(ap, wchar_t *);
    if (fq->p)
        get_wstr(fq);
    else
        fq->s = ft_strdup("(null)");
    fq->l = ft_strlen(fq->s);
    if (fq->precision >= 0 && fq->precision < (int)fq->l)
	{
		t = fq->s;
		fq->s = ft_strsub(fq->s, 0, fq->precision);
		fq->l = fq->precision;
		ft_strdel(&t);
	}
	if (fq->width > fq->l)
	{
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l),
					fq->flags[ZERO] == '1' ? '0' : ' ');
	}
}
