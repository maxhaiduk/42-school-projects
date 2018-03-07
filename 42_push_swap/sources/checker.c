/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:13:10 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/07 11:03:00 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *a, int len)
{
	len--;
	while (len)
	{
		if (*((int *)a->content) > *((int *)a->next->content))
			return (0);
		a = a->next;
		len--;
	}
	return (1);
}

static int	rotations(t_list **a, t_list **b, char *line)
{
	if (ft_strequ(line, "ra") || ft_strequ(line, "rb") || ft_strequ(line, "rr") ||
		ft_strequ(line, "rra") || ft_strequ(line, "rrb") || ft_strequ(line, "rrr"))
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

static void	check_instructions(t_list **a, t_list **b, char **line)
{
	while (get_next_line(0, line) > 0)
	{
		if (ft_strequ(*line, "sa"))
			sa(*a, 0);
		else if (ft_strequ(*line, "sb"))
			sb(*b, 0);
		else if (ft_strequ(*line, "ss"))
			ss(*a, *b, 0);
		else if (ft_strequ(*line, "pa"))
			pa(a, b, 0);
		else if (ft_strequ(*line, "pb"))
			pb(a, b, 0);
		else if (rotations(a, b, *line))
			;	
		else
			error("incorect instruction");
		ft_strdel(line);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (write(2, "Usage: ./checker [array]\n", 27));
	else if (argc == 2)
		a = parse_string(argv[1]);
	else
		a = parse_args(argv);
	check_instructions(&a, &b, &line);
	len = ft_lstlen(a);
	if (is_sorted(a, len))
		ft_printf(GREEN "OK\n" RESET);
	else
		ft_printf(RED "KO\n" RESET);
	ft_lst_erase(a);
	return (0);
}
