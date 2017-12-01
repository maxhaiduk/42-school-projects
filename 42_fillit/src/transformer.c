/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:25:11 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/12/01 17:57:28 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/transformer.h"
#include "../libft/libft.h"

static char	*get_row(t_list **head)
{
	int		i;
	char	*row;

	row = ft_strnew(4);
	i = 0;
	while (i < 4)
	{
		if ((**head)->next != '\n')
			row[i] = (**head)->next;
		i++;
		*head = (**head)->next;
	}
	return (row);
}

char		***transform_input(t_list head, int tet_num)
{
	int i;
	int j;
	char ***composition;
	char **tetro;
	char *row;

	composition = (char ***)malloc(sizeof(char **) * (tet_num + 1));
	if (!tetros)
		return (0);
	while (i < tet_num)
	{
		j = 0;
		tetro = (char **)malloc(sizeof(char *) * 5);
		while (j < 4)
		{
			row = get_row(&head);
			tetro[j] = row;
			j++;
		}
		tetro[j] = 0;
		composition[i] = tetro;
		i++;
	}
	composition[i] = 0;
}
