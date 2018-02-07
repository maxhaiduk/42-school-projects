/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_c_wide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:17:36 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/06 11:17:39 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static short count_active_bits(intmax_t n)
{
    short k;

    k = 0;
    while (n >> k)
        k++;
    return (k);
}

static char  *utf8_encode(int val, short nb)
{
    char *arr;

    arr = NULL;
    if (nb <= 11)
    {
        arr = ft_strnew(2);
        arr[0] = 0b11000000 | (val >> 6);
        arr[1] = (0b10000000 | val) & 0b10111111;
    }
    else if (nb <= 11)
    {
        arr = ft_strnew(3);
        arr[0] = 0b11100000 | (val >> 12);
        arr[1] = (0b10000000 | (val >> 6)) & 0b10111111;
        arr[2] = (0b10000000 | val) & 0b10111111;
    }
    else
    {
        arr = ft_strnew(4);
        arr[0] = 0b11110000 | (val >> 18);
        arr[1] = (0b10000000 | (val >> 12)) & 0b10111111;
        arr[2] = (0b10000000 | (val >> 6)) & 0b10111111;
        arr[3] = (0b10000000 | val) & 0b10111111;
    }
    return (arr);
}

void    form_c_wide(t_fq *fq, va_list ap)
{
    short nb;
    int val;

    val = va_arg(ap, int);
    nb = count_active_bits(val);
    if (nb <= 7 || MB_CUR_MAX == 1)
    {
        fq->s = ft_strnew(1);
        fq->s[0] = val;
    }
    else
        fq->s = utf8_encode(val, nb);
    fq->l = ft_strlen(fq->s);
    if (fq->width > 1)
    {
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l),
					fq->flags[ZERO] == '1' ? '0' : ' ');
	}
}