/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:51:42 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/23 14:19:39 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//__attribute__ ((unused))

static void init_types(char *types)
{
	types[0] = 's';
    types[1] = '\0';
}

/*
** Searching for type and put it to structure
** Such as type is the last part of qualifier, indent for can be calculated; 
*/

const char	*check_type(const char *qual, t_fq *fq __attribute__ ((unused)))
{
	static char		types[2];
	const char		*temp;
	char			*type;

	if (!types[0])
		init_types(types);
	temp = qual;
	while (*temp)
	{
		if ((type = ft_strchr(types, *temp)))
		{
			fq->type = *type;
			fq->indent = temp - qual + 1;
			//printf("type: %s, qual: %s, - : %li\n", type, qual, type - qual);
			//printf("\nindent %i\n", fq->indent);
			return (temp);
		}
		temp++;
	}
	return (NULL);
}

int		parse_qualifier(const char *qual, t_fq *fq)
{
	const char	*type_place;

	type_place = check_type(qual, fq);

	return (0);
}

static void	init_struct(t_fq *fq)
{
	fq->flag = '\0';
	fq->width = 0;
	fq->precision = 0;
	fq->size = 0;
	fq->type = '\0';
	fq->indent = 0;
}

/*
** Goes through the format string, looking for the % symbol
** If % was found - parse qualifier by filling stuct fq;
** Then next ap should be written on stdout;
*/

int		print_format(const char *format, va_list ap __attribute__ ((unused)))
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
		parse_qualifier(needle, &fq);
		form_output(ap, &fq);
		count += write(1, fq.str_out, ft_strlen(fq.str_out));
		needle += fq.indent;
		fiber = needle;
	}
	write(1, fiber, ft_strlen(fiber));
	count += ft_strlen(fiber);
	ft_putendl("Symbols counter");
	ft_putnbr(count);
	ft_putstr("\n");
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	count = 0;
	va_start(ap, format);
	count = print_format(format, ap);
	va_end(ap);
	return (count);
}
