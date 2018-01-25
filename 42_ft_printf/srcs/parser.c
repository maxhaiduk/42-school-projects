/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:24:12 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/25 12:17:48 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Searching for type and put it to structure
** Such as type is the last part of qualifier, indent for can be calculated;
*/

static void			init_types(char *types)
{
	types[0] = 's';
	types[1] = 'c';
	types[2] = '%';
	types[3] = 'n';
	types[4] = '\0';
}

static const char 	*check_type(const char *qual, t_fq *fq)
{
	static char		types[5];
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
			fq->indent = temp - qual + 2;
			return (temp);
		}
		temp++;
	}
	return (NULL);
}

static void			init_flags_values(char *fv)
{
	fv[0] = '-';
	fv[1] = '+';
	fv[2] = ' ';
	fv[3] = '#';
	fv[4] = '0';
	fv[5] = '\0';
}

static void			check_flags(char *q_str, t_fq *fq)
{
	static char fv[6];
	char		*tmp;

	if (!fv[0])
		init_flags_values(fv);
	while (*q_str)
	{
		if ((tmp = ft_strchr(fv, *q_str)))
			fq->flags[tmp - fv] = '1';
		q_str++;
	}
}

void print_flags(t_fq *fq)
{
	printf("flags: %s\n", fq->flags);
	printf("\nWidth: %zu\n", fq->width);
	printf("Precision: %i\n", fq->precision);
	printf("Size: %i\n", fq->size);
}

int					parse_qualifier(const char *qual, t_fq *fq, va_list ap)
{
	const char  *type_place;
	char		*q_str;

	type_place = check_type(qual + 1, fq);
	q_str = ft_strsub(qual, 0, type_place - qual);
	if (q_str[1])
	{
		check_width(q_str, fq, ap);
		check_flags(q_str, fq);
		check_precision(q_str, fq, ap);
		check_size(q_str, fq);
		//print_flags(fq);
	}
	//printf("q_str: %s :: len %lu\n", q_str, ft_strlen(q_str));
	free(q_str);

	return (0);
}
