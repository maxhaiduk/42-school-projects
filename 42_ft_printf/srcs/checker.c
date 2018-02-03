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

	i = 1;
	while (q_str[i])
	{
		if (q_str[i] == '.')
			return ;
		if (q_str[i] == '*')
		{
			t = va_arg(ap, int);
			if (t < 0 && t != 0)
				fq->flags[MINUS] = '1';
			fq->width = FT_ABS(t);
			//return ;
		}
		if (ft_isdigit(q_str[i]) && q_str[i] != '0')
		{
			fq->width = ft_atoi(&(q_str[i]));
			while (ft_isdigit(q_str[i]))
			{
				q_str[i] = '_';
				if (!ft_isdigit(q_str[i + 1]))
					break ;
				i++;
			}
			//return ;
		}
		i++;
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
