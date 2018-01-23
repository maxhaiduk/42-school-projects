/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:52:28 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/23 12:42:57 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef enum	e_size_modificator
{
	hh = 1,
	h  = 2,
	l  = 3,
	ll = 4,
	j  = 5,
	z  = 6
}				t_sm;

typedef struct	s_format_qualifier
{
	char		flag;
	int			width;
	int			precision;
	t_sm		size;
	char		type;
	int			indent;
	char		*str_out;
}				t_fq;

int				ft_printf(const char *format, ...);

int				form_output(va_list ap, t_fq *fq);

#endif
