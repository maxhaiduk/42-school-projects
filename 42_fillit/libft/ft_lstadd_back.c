/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:19:13 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/11 15:04:33 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (alst && *alst && new)
	{
		temp = *alst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
}
