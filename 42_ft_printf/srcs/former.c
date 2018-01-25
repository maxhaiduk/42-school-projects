/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   former.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:29:41 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/25 09:01:34 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_left(char *s, size_t width, size_t len)
{
	char	*temp;
	size_t	i;

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

char	*fill_right(char *s, size_t width, size_t len)
{
	char	*temp;
	size_t	i;
	size_t	diff;

	temp = ft_strnew(width);
	diff = width - len;
	i = 0;
	while (i < width)
	{
		if (i < diff)
			temp[i] = ' ';
		else
			temp[i] = s[i - diff];
		i++;
	}
	return (temp);
}

int		form_s(t_fq *fq, va_list ap)
{
	char	*s;
	char	*t;
	size_t	len;

	s = ft_strdup(va_arg(ap, char *));
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
			s = fill_left(s, fq->width, len);
		else
			s = fill_right(s, fq->width, len);
		ft_strdel(&t);
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
