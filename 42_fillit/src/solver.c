/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:31:46 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/12/02 18:09:28 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

static int	is_possible(t_coords a_c, char **board, int b_size, t_tetro *tetro)
{
	int			i;
	t_coords	temp;

	i = 0;
	while (i < 4)
	{
		temp.row = a_c.row + tetro->coords[i].row;
		temp.col = a_c.col + tetro->coords[i].col;
		if (temp.row < 0 || temp.row >= b_size ||
			temp.col < 0 || temp.col >= b_size ||
			board[temp.row][temp.col] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	set_tetro(t_coords a_c, char ***board, t_tetro *tetro)
{
	int			i;
	t_coords	temp;

	i = 0;
	while (i < 4)
	{
		temp.row = a_c.row + tetro->coords[i].row;
		temp.col = a_c.col + tetro->coords[i].col;
		(*board)[temp.row][temp.col] = tetro->label;
		i++;
	}
}

static int	backtracking(int b_size, char **board, t_tetro *tetro)
{
	t_coords	a_c;
	int			succes;

	if (!tetro)
	{
		print_board(board);
		return (1);
	}
	a_c.row = 0;
	succes = 0;
	while (a_c.row < b_size)
	{
		a_c.col = 0;
		while (a_c.col < b_size)
		{
			if (is_possible(a_c, board, b_size, tetro))
			{
				set_tetro(a_c, &board, tetro);
				succes = backtracking(b_size, dup_board(board, b_size), tetro->next);
				if (succes)
					return (1);
			}
			a_c.col++;
		}
		a_c.row++;
	}
	return (succes);
}

void		solve_problem(t_tetro *tetro, int tet_num)
{
	int		b_size;
	char	**board;
	int		succes;

	b_size = get_initial_size(tet_num);
	succes = 0;
	while (b_size)
	{
		board = create_board(b_size);
		succes = backtracking(b_size, dup_board(board, b_size), tetro->next);
		if (succes)
			break;
		b_size++;
	}
}
