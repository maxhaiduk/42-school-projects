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

size_t  wstr_len(int *wstr)
{
    
}

void    form_s_wide(t_fq *fq, va_list ap)
{
    printf("OK! I`m here!\n");
    fq->p = va_arg(ap, int *);
    fq->s = ft_strnew(wstr_len(fq->p));
}
