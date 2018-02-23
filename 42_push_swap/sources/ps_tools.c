/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:35:47 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/23 14:28:06 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_tools.h"

void    ps_swap(t_list *head)
{
    void *temp;

    if (head && head->next)
    {
        temp = head->content;
        head->content = head->next->content;
        head->next->content = temp;
    }
}

void ps_rotate(t_list **head)
{
    t_list *first;
    t_list *last;

    if (!*head || !(*head)->next)
        return ;
    first = *head;
    *head = (*head)->next;
    last = *head;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}