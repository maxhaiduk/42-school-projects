/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:51:42 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/24 14:57:19 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//__attribute__ ((unused))

/*
** Goes through the format string, looking for the % symbol
** If % was found - parse qualifier by filling stuct fq;
** Then next ap should be written on stdout;
*/

static void	init_struct(t_fq *fq)
{
	ft_memset(fq->flags, '0', 5);
	fq->flags[5] = '\0';
	fq->width = 0;
	fq->precision = -1;
	fq->size = 0;
	fq->type = '\0';
	fq->indent = 0;
}

int		perform(const char *format, va_list ap)
{
	const char	*needle;
	const char	*fiber;
	int			count;
	t_fq		fq;

	count = 0;
	fiber = format;
	while ((needle = ft_strchr(fiber, '%')))
	{
		if (needle - fiber)
		{
			count += (needle - fiber);
			write(1, fiber, needle - fiber);
		}
		init_struct(&fq);
		parse_qualifier(needle, &fq, ap);
		form_output(ap, &fq);
		count += write(1, fq.str_out, ft_strlen(fq.str_out));
		needle += fq.indent;
		fiber = needle;
	}
	write(1, fiber, ft_strlen(fiber));
	count += ft_strlen(fiber);
/*	ft_putstr("Symbols counter: ");
	ft_putnbr(count);
	ft_putstr("\n");*/
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	count = 0;
	va_start(ap, format);
	count = perform(format, ap);
	va_end(ap);
	return (count);
}
