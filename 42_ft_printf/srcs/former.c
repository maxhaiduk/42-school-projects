/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   former.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:29:41 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/27 09:26:15 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_left(char *s, size_t width, size_t *len, char c)
{
	char	*t;
	size_t	i;

	t = ft_strnew(width);
	i = 0;
	while (i < width)
	{
		if (i < *len)
			t[i] = s[i];
		else
			t[i] = c;
		i++;
	}
	*len = width;
	ft_strdel(&s);
	return (t);
}

char	*fill_right(char *s, size_t width, size_t *len, char c)
{
	char	*t;
	size_t	i;
	size_t	diff;

	t = ft_strnew(width);
	diff = width - *len;
	i = 0;
	while (i < width)
	{
		if (i < diff)
			t[i] = c;
		else
			t[i] = s[i - diff];
		i++;
	}
	*len = width;
	ft_strdel(&s);
	return (t);
}
/*
void	form_elips(t_fq *fq)
{
	char	*s;
	char	c;

	s = ft_strnew(1);
	s[0] = '%';
	if (fq->width > 1)
	{
		if (fq->flags[ZERO] == '1')
			c = '0';
		else
			c = ' ';
		if (fq->flags[MINUS] == '1')
			s = fill_left(s, fq->width, 1, ' ');
		else
			s = fill_right(s, fq->width, 1, c);
	}
	fq->str_out = s;
	fq->str_len = (fq->width > 1) ? fq->width : 1;
}*/

int		form_output(va_list ap, t_fq *fq)
{
	if (fq->type == 's')
		form_s(fq, ap);
/*	if (fq->type == 'c')
		form_c(fq, ap);
	if (fq->type == 'i' || fq->type == 'd')
		form_i_d(fq, ap);
	if (fq->type == '%')
		form_elips(fq);*/
	return (0);
}
