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
	free(s);
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
	free(s);
	return (t);
}

void	form_elips(t_fq *fq)
{
	char	c;

	fq->s = ft_strnew(1);
	fq->s[0] = '%';
	fq->l = 1;
	if (fq->width > 1)
	{
		c = fq->flags[ZERO] == '1' ? '0' : ' ';
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l), c);
	}
}

int		form_output(va_list ap, t_fq *fq)
{
	if (fq->type == 's')
		form_s(fq, ap);
	if (fq->type == 'c')
		form_c(fq, ap);
	if (fq->type == 'i' || fq->type == 'd')
		form_i_d(fq, ap);
	if (fq->type == 'x' || fq->type == 'X' ||
		fq->type == 'o' || fq->type == 'O' ||
		fq->type == 'u' || fq->type == 'U')
		form_x_o_u(fq, ap);
	if (fq->type == '%')
		form_elips(fq);
	return (0);
}
