/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:36:16 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/23 14:20:40 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;

    if (argc != 2)
        return(write(2, "Usage: ./push_swap [array]\n", 27));
    stack_a = read_array(argv[1]);
    print_list(stack_a);
    ft_printf("______\n");
    ps_swap(stack_a);
    print_list(stack_a);
    ft_printf("______\n");
    ps_rotate(&stack_a);
    print_list(stack_a);
    ft_lst_erase(stack_a);
    return (0);
}