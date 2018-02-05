/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:51:42 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/25 13:03:04 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	fq->s = NULL;
	fq->l = 0;
}

void		write_counter(va_list ap, int count)
{
	int *dest;

	dest = va_arg(ap, int *);
	*dest = count;
}

void		perform(const char *format, va_list ap, int *count)
{
	const char	*needle;
	const char	*fiber;
	t_fq		fq;
	size_t		len;

	fiber = format;
	while ((needle = ft_strchr(fiber, '%')))
	{
		*count += (needle - fiber);
		write(1, fiber, needle - fiber);
		init_struct(&fq);
		parse_qualifier(needle, &fq, ap);
		if (fq.type == 'n')
				write_counter(ap, *count);
		else if (fq.type)
		{
			if (fq.type != 't')
				form_output(ap, &fq);
			*count += write(1, fq.s, fq.l);
			free(fq.s);
		}
		needle += fq.indent;
		fiber = needle;
	}
	write(1, fiber, (len = ft_strlen(fiber)));
	*count += len;
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	count = 0;
	va_start(ap, format);
	perform(format, ap, &count);
	va_end(ap);
	return (count);
}
