/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:19:27 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/23 18:03:33 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void check_width(char *q_str, t_fq *fq, va_list ap)
{
	int i;

	i = 1;
	while (q_str[i])
	{
		if (q_str[i] == '.')
			return ;
		if (q_str[i] == '*')
		{
			fq->width = va_arg(ap, int);
			return ;
		}
		if (ft_isdigit(q_str[i]))
		{
			fq->width = ft_atoi(&(q_str[i]));
			return ;
		}
		i++;
	}
}

void check_precision(char *q_str, t_fq *fq, va_list ap)
{
	char	*dot;

	if((dot = ft_strchr(q_str, '.')))
	{
		if (*(dot + 1) == '*')
		{
			fq->precision = va_arg(ap, int);
			return ;
		}
		fq->precision = ft_atoi(dot + 1);
	}
}
