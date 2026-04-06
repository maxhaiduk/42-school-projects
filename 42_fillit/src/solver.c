/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:31:46 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/12/04 10:53:52 by mhaiduk          ###   ########.fr       */
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

static void	set_tetro(t_coords a_c, char **board, t_tetro *tetro)
{
	int			i;
	t_coords	temp;

	i = 0;
	while (i < 4)
	{
		temp.row = a_c.row + tetro->coords[i].row;
		temp.col = a_c.col + tetro->coords[i].col;
		board[temp.row][temp.col] = tetro->label;
		i++;
	}
}

static void	unset_tetro(t_coords a_c, char **board, t_tetro *tetro)
{
	int			i;
	t_coords	temp;

	i = 0;
	while (i < 4)
	{
		temp.row = a_c.row + tetro->coords[i].row;
		temp.col = a_c.col + tetro->coords[i].col;
		board[temp.row][temp.col] = '.';
		i++;
	}
}

static int	backtracking(int b_size, char **board, t_tetro *tetro)
{
	t_coords	a_c;

	if (!tetro)
	{
		print_board(board);
		return (1);
	}
	a_c.row = 0;
	while (a_c.row < b_size)
	{
		a_c.col = 0;
		while (a_c.col < b_size)
		{
			if (is_possible(a_c, board, b_size, tetro))
			{
				set_tetro(a_c, board, tetro);
				if (backtracking(b_size, board, tetro->next))
					return (1);
				unset_tetro(a_c, board, tetro);
			}
			a_c.col++;
		}
		a_c.row++;
	}
	return (0);
}

void		solve_problem(t_tetro *tetro, int tet_num)
{
	int		b_size;
	char	**board;

	b_size = get_initial_size(tet_num);
	while (b_size)
	{
		board = create_board(b_size);
		if (backtracking(b_size, board, tetro->next))
		{
			free_board(board);
			break ;
		}
		free_board(board);
		b_size++;
	}
}
