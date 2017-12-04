/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:54:09 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/12/04 11:20:12 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CHECKER_H
# define INPUT_CHECKER_H

# include "../libft/libft.h"

typedef struct	s_map_cont
{
	int			hashes;
	int			dots;
	int			new_lines;
}				t_map_cont;

int				check_input(t_list *head);

#endif
