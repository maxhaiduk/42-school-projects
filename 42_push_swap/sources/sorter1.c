/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/01 14:56:11 by mhaiduk          ###   ########.fr       */
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

void	primal_dividing(t_list **a, t_list **b)
{
	t_list *temp;
	int len;
	int med;

	len = (int)ft_lstlen(*a);
	len = len % 2 ? len / 2 + 1 : len / 2;
	med = get_mediana(*a, len);
	ft_printf("Mediana is %i\n", med);
	while (len)
	{
		if (VAL(a) > med)
			ra(a);
		else
		{
			pb(a, b);
			len--;
		}
		print_stacks(*a, *b);
	}
	temp = *a;
	while (temp)
	{
		temp->content_size = med;
		ft_printf("NODE: content: %i\ncontent size: %i\n", *((int *)temp->content), temp->content_size);
		temp = temp->next;
	}
}

void	empty_b_stack(t_list **a, t_list **b)
{
	int len;
	int med;

	if (!(*b)->next)
	{
		pa(a, b);
		return ;
	}
	len = (int)ft_lstlen(*b);
	med = len % 2 ? len / 2 + 1 : len / 2;
	med = get_mediana(*b, med);
	len = len / 2;
	while (len)
	{
		if (VAL(b) <= med)
			ra(b);
		else
		{
			(*b)->content_size = med;
			pa(a, b);
			len--;
		}
		print_stacks(*a, *b);
	}
	empty_b_stack(a, b);
}

void	sort_stack(t_list *a)
{
	t_list *b;

	b = NULL;
	print_stacks(a, b);
	primal_dividing(&a, &b);
	empty_b_stack(&a, &b);
	print_stacks(a, b);
}