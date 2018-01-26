/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:19:27 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/26 14:07:43 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_width(char *q_str, t_fq *fq, va_list ap)
{
	int i;
	int t;

	i = 0;
	while (q_str[++i])
	{
		if (q_str[i] == '.')
			return ;
		if (q_str[i] == '*')
		{
			t = va_arg(ap, int);
			fq->width = FT_ABS(t);
			return ;
		}
		if (ft_isdigit(q_str[i]) && q_str[i] != '0')
		{
			fq->width = ft_atoi(&(q_str[i]));
			while (ft_isdigit(q_str[i]))
			{
				q_str[i] = '_';
				i++;
			}
			return ;
		}
	}
}

void	check_precision(char *q_str, t_fq *fq, va_list ap)
{
	char	*dot;

	if ((dot = ft_strchr(q_str, '.')))
	{
		if (*(dot + 1) == '*')
		{
			fq->precision = va_arg(ap, int);
			return ;
		}
		fq->precision = ft_atoi(dot + 1);
	}
}

void	check_size(char *q_str, t_fq *fq)
{
	if (ft_strstr(q_str, "hh"))
		fq->size = hh;
	else if (ft_strstr(q_str, "h"))
		fq->size = h;
	else if (ft_strstr(q_str, "ll"))
		fq->size = ll;
	else if (ft_strstr(q_str, "l"))
		fq->size = l;
	else if (ft_strstr(q_str, "j"))
		fq->size = j;
	else if (ft_strstr(q_str, "z"))
		fq->size = z;
}
