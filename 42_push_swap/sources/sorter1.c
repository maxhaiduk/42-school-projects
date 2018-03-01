/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/01 17:07:48 by mhaiduk          ###   ########.fr       */
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

int		get_stack_len(t_list *a)
{
	int len;

	len = 0;
	while (a)
	{
		ft_printf("NODE: content: %i\ncontent size: %i\n", *((int *)a->content), a->content_size);
		len++;
		if (a->next && a->content_size != a->next->content_size)
			break;
		a = a->next;
	}
	return (len);
}

void	primal_dividing(t_list **a, t_list **b)
{
	t_list *temp;
	int len;
	int med;

	len = get_stack_len(*a);
	med = len % 2 ? len / 2 + 1 : len / 2;
	med = get_mediana(*a, len, med);
	len = len % 2 ? len / 2 + 1 : len / 2;
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
		(*b)->content_size = FINISH;
		pa(a, b);
		return ;
	}
	len = (int)ft_lstlen(*b);
	med = len % 2 ? len / 2 + 1 : len / 2;
	med = get_mediana(*b, len, med);
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

void put_back(t_list **a, t_list **b)
{
	int p;
	int n;

	ra(a);
	p = 2;
	while (p)
	{
		n = get_stack_len(*a);
		if (n == 1)
			ra(a);
		else if (n == 2)
		{
			if (VAL(a) > VAL_NEXT(a))
				sa(*a);
			ra(a);
			ra(a);
		}
		p--;
		print_stacks(*a, *b);
	}
}

void 	push_to_b(t_list **a, t_list **b)
{
	int len;

	len = get_stack_len(*a);
	while (len)
	{
		pb(a, b);
		len--;
		print_stacks(*a, *b);
	}
}

void	sort_stack(t_list *a)
{
	t_list *b;

	b = NULL;
	print_stacks(a, b);
	primal_dividing(&a, &b);
	empty_b_stack(&a, &b);
	print_stacks(a, b);
	put_back(&a, &b);
	print_stacks(a, b);
	while (a->content_size != FINISH)
	{
		push_to_b(&a, &b);
		print_stacks(a, b);
		empty_b_stack(&a, &b);
		print_stacks(a, b);
		put_back(&a, &b);
		print_stacks(a, b);
	}
}