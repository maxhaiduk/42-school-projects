/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:47:11 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/07 17:07:42 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		read_stat(char *line, int *stats)
{
	if (ft_strequ(line, "sa"))
		stats[SA]++;
	else if (ft_strequ(line, "sb"))
		stats[SB]++;
	else if (ft_strequ(line, "ss"))
		stats[SS]++;
	else if (ft_strequ(line, "pa"))
		stats[PA]++;
	else if (ft_strequ(line, "pb"))
		stats[PB]++;
	else if (ft_strequ(line, "ra"))
		stats[RA]++;
	else if (ft_strequ(line, "rb"))
		stats[RB]++;
	else if (ft_strequ(line, "rr"))
		stats[RR]++;
	else if (ft_strequ(line, "rra"))
		stats[RRA]++;
	else if (ft_strequ(line, "rrb"))
		stats[RRB]++;
	else if (ft_strequ(line, "rrr"))
		stats[RRR]++;
}

static int	get_sum(int stats[11])
{
	int sum;
	int i;

	i = 0;
	sum = 0;
	while (i < 11)
	{
		sum += stats[i];
		i++;
	}
	return (sum);
}

void		print_stats(int s[11])
{
	int sum;

	sum = get_sum(s);
	if (!sum)
		error("no operations for statistics");
	ft_printf("\nSTATISTICS:\n\n");
	s[SA] ? ft_printf("sa  : %3i %7.1f%%\n", s[SA], s[SA] * 100.0 / sum) : 0;
	s[SB] ? ft_printf("sb  : %3i %7.1f%%\n", s[SB], s[SB] * 100.0 / sum) : 0;
	s[SS] ? ft_printf("ss  : %3i %7.1f%%\n", s[SS], s[SS] * 100.0 / sum) : 0;
	s[PA] ? ft_printf("pa  : %3i %7.1f%%\n", s[PA], s[PA] * 100.0 / sum) : 0;
	s[PB] ? ft_printf("pb  : %3i %7.1f%%\n", s[PB], s[PB] * 100.0 / sum) : 0;
	s[RA] ? ft_printf("ra  : %3i %7.1f%%\n", s[RA], s[RA] * 100.0 / sum) : 0;
	s[RB] ? ft_printf("rb  : %3i %7.1f%%\n", s[RB], s[RB] * 100.0 / sum) : 0;
	s[RR] ? ft_printf("rr  : %3i %7.1f%%\n", s[RR], s[RR] * 100.0 / sum) : 0;
	s[RRA] ? ft_printf("rra : %3i %7.1f%%\n", s[RRA], s[RRA] * 100.0 / sum) : 0;
	s[RRB] ? ft_printf("rrb : %3i %7.1f%%\n", s[RRB], s[RRB] * 100.0 / sum) : 0;
	s[RRR] ? ft_printf("rrr : %3i %7.1f%%\n", s[RRR], s[RRR] * 100.0 / sum) : 0;
	ft_printf("\nTotal number of operations : %i\n\n", sum);
}
