/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   former.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:29:41 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/25 14:49:51 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_left(char *s, size_t width, size_t len, char c)
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
			temp[i] = c;
		i++;
	}
	return (temp);
}

char	*fill_right(char *s, size_t width, size_t len, char c)
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
			temp[i] = c;
		else
			temp[i] = s[i - diff];
		i++;
	}
	return (temp);
}

void	form_elips(t_fq *fq)
{
	char	*s;
	char	*t;
	char	c;

	s = ft_strnew(1);
	s[0] = '%';
	if (fq->width > 1)
	{
		t = s;
		if (fq->flags[ZERO] == '1')
			c = '0';
		else
			c = ' ';
		if (fq->flags[MINUS] == '1')
			s = fill_left(s, fq->width, 1, ' ');
		else
			s = fill_right(s, fq->width, 1, c);
		ft_strdel(&t);
	}
	fq->str_out = s;
	fq->str_len = (fq->width > 1) ? fq->width : 1;
}

int		form_output(va_list ap, t_fq *fq)
{
	if (fq->type == 's')
		form_s(fq, ap);
	if (fq->type == 'c')
		form_c(fq, ap);
	if (fq->type == '%')
		form_elips(fq);
	return (0);
}
