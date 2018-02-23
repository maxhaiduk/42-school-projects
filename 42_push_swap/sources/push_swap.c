/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:36:16 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/23 16:58:12 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;
    argc = 0;
    if (argc != 2)
        return(write(2, "Usage: ./push_swap [array]\n", 27));
    a = read_array(argv[1]);
    ft_printf("Initial stack:\n");
    print_list(a);
    
    ft_printf("\nPush from a to b:");
    ps_push(&a, &b);
    ps_push(&a, &b);
    ps_push(&a, &b);
    ft_printf("\nStack a\n");
    print_list(a);

    ft_printf("\nStack b\n");
    print_list(b);

    ft_lst_erase(a);
    ft_lst_erase(b);
    return (0);
}