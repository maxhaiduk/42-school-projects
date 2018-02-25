/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/25 20:08:32 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *get_tail(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head); 
}


// void	primal_dividing(t_list **a, t_list **b, t_list **tail_a, t_list **tail_b)
// {
// 	int len;
// 	int med;
// 	int x;
// 	int y;
// 	int z;

// 	while ((*a)->next)
// 	{
// 		med = get_mediana(*a);
// 		len = (int)ft_lstlen(*a) / 2;
// 		ft_printf("Mediana is %i\n", med);
// 		while (len)
// 		{
// 			if (*a && (*a)->next)
// 			{
// 				x = VAL(a);
// 				y = VAL(tail_a);
// 				z = VAL_NEXT(a);
// 				if (x < med && is_min(x, y, z))
// 					;
// 				else if (z < med && is_min(z, y, x))
// 					sa(*a);
// 				else if (y < med && is_min(y, x, z))
// 					rra(a, tail_a);
// 				else
// 					ra(a, tail_a);
// 				if (VAL(a) < med)
// 				{
// 					pb(a, b);
// 					len--;
// 				}
// 			}
// 			if (*b && (*b)->next)
// 			{
// 				if (!(*tail_b))
// 					*tail_b = get_tail(*b);
// 				x = VAL(b);
// 				y = VAL(tail_b);
// 				z = VAL_NEXT(b);
// 				if (x > y && x > z)
// 					;
// 				if (x < z && x > y)
// 					sb(*b);
// 				else if (x < y)
// 					rb(b, tail_b);
// 			}
// 			//en--;
// 			print_stacks(*a, *b);
// 		}
// 	}
// }

void divide_a(t_list **a, t_list **b, t_list **tail_a, t_list **tail_b, int len)
{
	int med;
	int temp;

	if (len == 1)
		return ;
	med = get_mediana(*a, len);
	temp = len;
	while (temp && (*a)->next)
	{
		ft_printf("Stack A; Mediana is %i\n", med);
		if (VAL(a) > med)
			ra(a, tail_a);
		else
			{
				pb(a, b);
				temp--;
			}
		print_stacks(*a, *b);
	}
	divide_a(a, b, tail_a, tail_b, len % 2 ? len / 2 + 1 : len / 2);
}

void divide_b(t_list **a, t_list **b, t_list **tail_a, t_list **tail_b, int len)
{
	int med;
	int temp;

	if (!len)
		return ;
	med = get_mediana(*b, len);
	temp = len;
	while (temp)
	{
		ft_printf("Stack B; Mediana is %i\n", med);
		if (VAL(b) <= med)
			rb(b, tail_b);
		else
			{
				pa(a, b);
				temp--;
			}
		print_stacks(*a, *b);
	}
	divide_b(a, b, tail_a, tail_b, len % 2 ? len / 2 : len / 2 - 1);
}

void	sort_stack(t_list *a)
{
	t_list *tail_a;
	t_list *b;
	t_list *tail_b;
	int len;
	// int med;
	// int num;
	//ft_printf("len is %i\n", ft_lstlen(a));
	len = ft_lstlen(a);
	ft_printf("len is %i\n", len);
	len = len % 2 ? len / 2 + 1 : len / 2;
	ft_printf("len is %i\n", len);
	ft_printf("Mediana is %i\n", get_mediana(a, len));

	b = NULL;
	tail_a = get_tail(a);
	len = ft_lstlen(a);
	tail_b = get_tail(b);
	print_stacks(a, b);
	//divide(&a, &b, &tail_a, &tail_b, len % 2 ? len / 2 + 1 : len / 2);
	divide_a(&a, &b, &tail_a, &tail_b, len % 2 ? len / 2 + 1 : len / 2);
	divide_b(&a, &b, &tail_a, &tail_b, len % 2 ? len / 2 : len / 2 - 1);
	// divide_a(&a, &b, &tail_a, &tail_b, ft_lstlen(a) / 4 + 1);
	// divide_b(&a, &b, &tail_a, &tail_b, ft_lstlen(b) / 4);

	//primal_dividing(&a, &b, &tail_a, &tail_b);
	// while (a->next)
	// {
	// 	med = get_mediana(a);
	// 	len = (int)ft_lstlen(a);
	// 	ft_printf("Mediana is %i\n", med);
	// 	while (len)
	// 	{
	// 		// if (a && a->next && VAL(a) < med)
	// 		// 	pb(&a, &b);
	// 		if (a && a->next && VAL(a) > VAL(a->next) && VAL(a->next) < med)
	// 			sa(a);
	// 		else if (VAL(tail_a) < med)
	// 			rra(&a, &tail_a);
	// 		if (VAL(a) >= med)
	// 			ra(&a, &tail_a);
	// 		else
	// 			pb(&a, &b);
	// 		len--;
	// 		print_stacks(a, b);
	// 	}
	//}
	// while (b)
	// {
	// 	if (b && b->next && VAL(b) < VAL(b->next))
	// 		sb(b);
	// 	pa(&a, &b);
	// 	if (a && a->next && VAL(a) > VAL(a->next))
	// 		sa(a);
	// 	print_stacks(a, b);
	// }
	
}