/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:13:10 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/11 15:41:48 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (*((int *)a->content) > *((int *)a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}

static int	rotations(t_list **a, t_list **b, char *line)
{
	if (ft_strequ(line, "ra") || ft_strequ(line, "rb") ||
		ft_strequ(line, "rr") || ft_strequ(line, "rra") ||
		ft_strequ(line, "rrb") || ft_strequ(line, "rrr"))
	{
		if (ft_strequ(line, "ra"))
			ra(a, 0);
		else if (ft_strequ(line, "rb"))
			rb(b, 0);
		else if (ft_strequ(line, "rr"))
			rr(a, b, 0);
		else if (ft_strequ(line, "rra"))
			rra(a, 0);
		else if (ft_strequ(line, "rrb"))
			rrb(b, 0);
		else if (ft_strequ(line, "rrr"))
			rrr(a, b, 0);
		return (1);
	}
	return (0);
}

static void	check_instructions(t_list **a, t_list **b, t_flags flags,
								int stats[11])
{
	char	*line;

	if (flags.v)
		print_stacks(*a, *b);
	while (get_next_line(0, &line) > 0)
	{
		flags.s ? read_stat(line, stats) : 0;
		if (ft_strequ(line, "sa"))
			sa(*a, 0);
		else if (ft_strequ(line, "sb"))
			sb(*b, 0);
		else if (ft_strequ(line, "ss"))
			ss(*a, *b, 0);
		else if (ft_strequ(line, "pa"))
			pa(a, b, 0);
		else if (ft_strequ(line, "pb"))
			pb(a, b, 0);
		else if (rotations(a, b, line))
			;
		else
			flags.e ? error("incorect instruction") : error(NULL);
		if (flags.v)
			print_stacks(*a, *b);
		ft_strdel(&line);
	}
}

int			main(int argc, char **argv)
{
	t_flags		flags;
	t_list		*a;
	t_list		*b;
	static int	stats[11];

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	argv++;
	flags = parse_flags(&argv);
	if (flags.h)
		print_help();
	if (!*argv)
		return (write(2, "Usage: ./checker [flags][array]\n", 33));
	a = (ft_len_strarr(argv) == 1) ? parse_string(*argv, flags) :
									parse_args(argv, flags);
	check_instructions(&a, &b, flags, stats);
	is_sorted(a) ? ft_printf("OK\n") : ft_printf("KO\n");
	if (flags.s)
		print_stats(stats);
	ft_lst_erase(a);
	return (0);
}
