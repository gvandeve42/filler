/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_rec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:53:53 by gvandeve          #+#    #+#             */
/*   Updated: 2017/04/13 15:54:18 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	test_pos_up(t_player *ply, int i, int j, int *test)
{
	if (ply->plateau[i - 1][j] == ply->symb[0] ||
		ply->plateau[i - 1][j] == ply->symb[1] ||
		ply->plateau[i - 1][j] == 'a')
	{
		test[0]++;
	}
	if (ply->plateau[i - 1][j] == ply->esymb[0] ||
		ply->plateau[i - 1][j] == ply->esymb[1])
	{
		test[1]++;
	}
	if (ply->plateau[i - 1][j] == '.')
	{
		ply->plateau[i][j] = 'b';
		filter_pos_rec(ply, i - 1, j, test);
	}
}

void	test_pos_down(t_player *ply, int i, int j, int *test)
{
	if (ply->plateau[i + 1][j] == ply->symb[0] ||
		ply->plateau[i + 1][j] == ply->symb[1] ||
		ply->plateau[i + 1][j] == 'a')
	{
		test[0]++;
	}
	if (ply->plateau[i + 1][j] == ply->esymb[0] ||
		ply->plateau[i + 1][j] == ply->esymb[1])
	{
		test[1]++;
	}
	if (ply->plateau[i + 1][j] == '.')
	{
		ply->plateau[i][j] = 'b';
		filter_pos_rec(ply, i + 1, j, test);
	}
}

void	test_pos_right(t_player *ply, int i, int j, int *test)
{
	if (ply->plateau[i][j + 1] == ply->symb[0] ||
		ply->plateau[i][j + 1] == ply->symb[1] ||
		ply->plateau[i][j + 1] == 'a')
	{
		test[0]++;
	}
	if (ply->plateau[i][j + 1] == ply->esymb[0] ||
		ply->plateau[i][j + 1] == ply->esymb[1])
	{
		test[1]++;
	}
	if (ply->plateau[i][j + 1] == '.')
	{
		ply->plateau[i][j] = 'b';
		filter_pos_rec(ply, i, j + 1, test);
	}
}

void	test_pos_left(t_player *ply, int i, int j, int *test)
{
	if (ply->plateau[i][j - 1] == ply->symb[0] ||
		ply->plateau[i][j - 1] == ply->symb[1] ||
		ply->plateau[i][j - 1] == 'a')
	{
		test[0]++;
	}
	if (ply->plateau[i][j - 1] == ply->esymb[0] ||
		ply->plateau[i][j - 1] == ply->esymb[1])
	{
		test[1]++;
	}
	if (ply->plateau[i][j - 1] == '.')
	{
		ply->plateau[i][j] = 'b';
		filter_pos_rec(ply, i, j - 1, test);
	}
}
