/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:36:16 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/03/04 20:37:20 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *a;
    int len;

    a = NULL;
    if (argc != 2)
        return(write(2, "Usage: ./push_swap [array]\n", 27));
    a = read_array(argv[1]);
    len = ft_lstlen(a);
    sort_stack(&a);
    //print_stacks(a, b);
    len = ft_lstlen(a);
    while (len)
    {
        ft_printf("%zu\n", *((int *)a->content));
        a = a->next;
        len--;
    }

    ft_lst_erase(a);
    return (0);
}