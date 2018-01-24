/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   former.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:29:41 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/24 16:04:59 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


char	*fill_left(char *s, int width)
{
	char	*temp;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	temp = ft_strnew(width);
	i = 0;
	while (i < width)
	{
		if (i < len)
			temp[i] = s[i];
		else
			temp[i] = ' ';
		i++;
	}
	return (temp);
}

int		form_s(t_fq *fq, va_list ap)
{
	char *s;
	char *t;

	t = va_arg(ap, char *);
	s = t; 
	if (fq->precision >= 0 && fq->precision < (int)ft_strlen(t))
		s = ft_strsub(t, 0, fq->precision);
	if (fq->width > (int)ft_strlen(s))
	{
		if (fq->flags[MINUS] == 1)
			t = fill_left(s, fq->width);
	}
	fq->str_out = s;
	return (0);
}

int		form_output(va_list ap, t_fq *fq)
{
	if (fq->type == 's')
		form_s(fq, ap);
	return (0);
}
