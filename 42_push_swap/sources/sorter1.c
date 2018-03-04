/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:40:30 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/04 13:32:22 by mhaiduk          ###   ########.fr       */
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
		//ft_printf("NODE: content: %i\ncontent size: %i\n", *((int *)a->content), a->content_size);
		len++;
		if (a->next && a->content_size != a->next->content_size)
			break;
		a = a->next;
	}
	return (len);
}

void	primal_dividing(t_list **a, t_list **b)
{
	int len;
	int med;
	int count;

	len = get_stack_len(*a);
	if (len <= 3)
		return ;
	count = len / 2;
	med = get_mediana(*a, len, len % 2 ? len / 2 + 1 : len / 2);
	ft_printf("Mediana is %i\n", med);
	while (count)
	{
		if ((len % 2 == 0 && VAL(a) > med) || (len % 2 == 1 && VAL(a) >= med))
			ra(a);
		else
		{
			(*a)->content_size = med;
			pb(a, b);
			count--;
		}
		print_stacks(*a, *b);
	}
	primal_dividing(a, b);
}

void	sort_stack(t_list *a)
{
	t_list *b;

	b = NULL;
	print_stacks(a, b);
	primal_dividing(&a, &b);
	print_stacks(a, b);
}