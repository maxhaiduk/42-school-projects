/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:37:45 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/15 15:31:47 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_flags(t_flags *flags)
{
	flags->v = 0;
	flags->e = 0;
	flags->s = 0;
	flags->h = 0;
}

static void	detect_flag(char *arg, t_flags *flags)
{
	if (ft_strequ(arg, "-v"))
		flags->v = 1;
	else if (ft_strequ(arg, "-e"))
		flags->e = 1;
	else if (ft_strequ(arg, "-s"))
		flags->s = 1;
	else if (ft_strequ(arg, "-h"))
		flags->h = 1;
	else
		flags->e ? error("incorrect flag (use ./checker -h for help)")
					: error(NULL);
}

t_flags		parse_flags(char ***args)
{
	t_flags	flags;

	init_flags(&flags);
	while (*args)
	{
		if (**args && ***args == '-' && !ft_is_number(**args))
			detect_flag(**args, &flags);
		else
			break ;
		(*args)++;
	}
	return (flags);
}

static void	detect_flag_ps(char *arg, t_flags *flags)
{
	if (ft_strequ(arg, "-e"))
		flags->e = 1;
	else if (ft_strequ(arg, "-h"))
		flags->h = 1;
	else
		flags->e ? error("incorrect flag (use ./push_swap -h for help)")
					: error(NULL);
}

t_flags		parse_flags_ps(char ***args)
{
	t_flags	flags;

	init_flags(&flags);
	while (*args)
	{
		if (**args && ***args == '-' && !ft_is_number(**args))
			detect_flag_ps(**args, &flags);
		else
			break ;
		(*args)++;
	}
	return (flags);
}