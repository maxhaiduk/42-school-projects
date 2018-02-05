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

static void	init_types(char *types)
{
	types[0] = 's';
	types[1] = 'c';
	types[2] = '%';
	types[3] = 'i';
	types[4] = 'd';
	types[5] = 'D';
	types[6] = 'x';
	types[7] = 'X';
	types[8] = 'o';
	types[9] = 'O';
	types[10] = 'u';
	types[11] = 'U';
	types[12] = 'p';
	types[13] = 'n';
	types[14] = '\0';
}

static int	check_type(char **qual, t_fq *fq)
{
	static char		types[15];
	char			*type;

	if (!types[0])
		init_types(types);
	if ((type = ft_strchr(types, **qual)))
	{
		fq->type = *type;
		return (1);
	}
	return (0);
}

static int	check_flags(char **q_str, t_fq *fq)
{
	static char fv[6];
	char		*tmp;

	if (!fv[0])
	{
		fv[0] = '-';
		fv[1] = '+';
		fv[2] = ' ';
		fv[3] = '#';
		fv[4] = '0';
		fv[5] = '\0';
	}
	if ((tmp = ft_strchr(fv, **q_str)))
	{
		fq->flags[tmp - fv] = '1';
		(*q_str)++;
		return (1);
	}
	return (0);
}

void		parse_qualifier(const char *qual, t_fq *fq, va_list ap)
{
	char *q_str;

	q_str = (char *)qual + 1;
	while (*q_str)
	{
		if (!(check_flags(&q_str, fq) ||
		check_width(&q_str, fq, ap) ||
		check_precision(&q_str, fq, ap) ||
		check_size(&q_str, fq) ||
		check_type(&q_str, fq)))
		{
			form_issue_out(fq, *q_str);
			break ;
		}
		else if (fq->type)
			break ;
	}
	if (fq->type)
		fq->indent = q_str - qual + 1;
	else
		fq->indent = q_str - qual;
}
