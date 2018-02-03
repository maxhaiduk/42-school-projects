/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:24:12 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/01 16:49:35 by mhaiduk          ###   ########.fr       */
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
	types[3] = 'i';
	types[3] = 'd';
	types[4] = 'x';
	types[5] = 'X';
	types[6] = 'o';
	types[7] = 'O';
	types[8] = 'u';
	types[9] = 'U';
	types[10] = 'p';
	types[11] = 'n';
	types[12] = '\0';
}

static const char	*check_type(const char *qual, t_fq *fq)
{
	static char		types[13];
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
	fq->indent = 1;
	return (qual);
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
		if (*q_str == '.')
			break ;
		if ((tmp = ft_strchr(fv, *q_str)))
			fq->flags[tmp - fv] = '1';
		q_str++;
	}
}

int					parse_qualifier(const char *qual, t_fq *fq, va_list ap)
{
	const char	*type_place;
	char		*q_str;

	type_place = check_type(qual + 1, fq);
	q_str = ft_strsub(qual, 0, type_place - qual);
	if (q_str[1])
	{
		check_width(q_str, fq, ap);
		check_flags(q_str, fq);
		check_precision(q_str, fq, ap);
		check_size(q_str, fq);
	}
	free(q_str);
	return (0);
}
