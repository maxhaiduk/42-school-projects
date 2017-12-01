/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:25:11 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/12/01 19:13:09 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/transformer.h"

static char	*get_row(t_list **head)
{
	int		i;
	char	*row;

	row = ft_strnew(4);
	i = 0;
	while (i < 4)
	{
		if (*(char *)((*head)->content) != '\n')
		{
			row[i] = *(char *)((*head)->content);
			i++;
		}
		*head = (*head)->next;
	}
	return (row);
}

static char	***transform_input(t_list *head, int tet_num)
{
	int i;
	int j;
	char ***composition;
	char **tetro;
	char *row;

	composition = (char ***)malloc(sizeof(char **) * (tet_num + 1));
	if (!composition)
		return (0);
	i = 0;
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
	return (composition);
}

void	fetch_coords(t_list *head, int tet_num)
{
	char ***composition;

	composition = transform_input(head, tet_num);
	

	while (*composition)
	{
		print_board(*composition);
		ft_putchar('\n');
		composition++;
	}
	
} 
