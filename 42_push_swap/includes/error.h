/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:13:56 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/02/15 16:13:57 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include <limits.h>

void	memory_error(void);
void	check_type(char **arr);
void	check_values(t_list *head);
void	check_duplicates(t_list *head);

#endif