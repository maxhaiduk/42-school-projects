/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:54:15 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/23 15:06:09 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *write_to_list(char **arr)
{
    t_list      *head;
    t_list      *tail;
    intmax_t    temp;

    temp = ft_atoi(*arr++);
    head = ft_lstnew(&temp, sizeof(intmax_t));
    if (!head)
        memory_error();
    tail = head;
    while (*arr)
    {
        temp = ft_atoi(*arr++);
        tail = ft_lstadd_back(tail, ft_lstnew(&temp, sizeof(intmax_t)));
    }
    return (head);
}

t_list *read_array(char *str)
{
    char    **arr;
    t_list  *head;

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