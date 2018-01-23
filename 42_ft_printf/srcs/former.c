/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   former.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:29:41 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/23 12:43:25 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		form_s(t_fq *fq, va_list ap)
{
	char *str;

	str = ft_strdup(va_arg(ap, char *));
	fq->str_out = str;
	return (0);
}

int		form_output(va_list ap, t_fq *fq)
{
	if (fq->type == 's')
		form_s(fq, ap);
	return (0);
}
