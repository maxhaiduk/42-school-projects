/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:54:15 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/07 17:14:46 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*write_to_list(char **arr)
{
	t_list		*head;
	t_list		*tail;
	intmax_t	temp;

	temp = ft_atoi(*arr++);
	head = ft_lstnew(&temp, sizeof(intmax_t));
	if (!head)
		error("memory allocation failed");
	tail = head;
	while (*arr)
	{
		temp = ft_atoi(*arr++);
		tail = ft_lstadd_back(tail, ft_lstnew(&temp, sizeof(intmax_t)));
	}
	return (head);
}

t_list	*parse_string(char *str)
{
	char	**arr;
	t_list	*head;

	arr = ft_strsplit(str, ' ');
	if (!*arr)
		error("array is empty");
	check_type(arr);
	head = write_to_list(arr);
	check_values(head);
	check_duplicates(head);
	ft_clear_strarr(&arr);
	return (head);
}

t_list	*parse_args(char **args)
{
	t_list	*head;

	check_type(args);
	head = write_to_list(args);
	check_values(head);
	check_duplicates(head);
	return (head);
}
