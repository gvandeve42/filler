/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:13:05 by gvandeve          #+#    #+#             */
/*   Updated: 2017/03/29 13:16:55 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos	*fill_pos_player(t_player *ply, int x, int y, t_pos *lst)
{
	if (ply->plateau[x][y] == ply->symb[0] ||
		ply->plateau[x][y] == ply->symb[1])
	{
		lst = add_elem(x, y, lst);
		ply->plateau[x][y] = 'A';
		if ((x + 1) < ply->iplateau[1])
			fill_pos_player(ply, (x + 1), y, lst);
		if ((x - 1) > -1)
			fill_pos_player(ply, (x - 1), y, lst);
		if ((y + 1) < ply->iplateau[0])
			fill_pos_player(ply, x, (y + 1), lst);
		if ((y - 1) > -1)
			fill_pos_player(ply, x, (y + 1), lst);
	}
	return (lst);
}

t_pos	*fill_pos_eplayer(t_player *ply, int x, int y, t_pos *lst)
{
	if (ply->plateau[x][y] == ply->esymb[0] ||
		ply->plateau[x][y] == ply->esymb[1])
	{
		lst = add_elem(x, y, lst);
		ply->plateau[x][y] = 'B';
		if ((x + 1) < ply->iplateau[1])
			fill_pos_eplayer(ply, (x + 1), y, lst);
		if ((x - 1) > -1)
			fill_pos_eplayer(ply, (x - 1), y, lst);
		if ((y + 1) < ply->iplateau[0])
			fill_pos_eplayer(ply, x, (y + 1), lst);
		if ((y - 1) > -1)
			fill_pos_eplayer(ply, x, (y + 1), lst);
	}
	return (lst);
}

t_pos	*fill_pos_pic(t_player *ply, int x, int y, t_pos *lst)
{
	if (ply->piece[x][y] == '*')
	{
		lst = add_elem(x, y, lst);
		ply->piece[x][y] = 'C';
		if ((x + 1) < ply->ipiece[1])
			fill_pos_pic(ply, (x + 1), y, lst);
		if ((x - 1) > -1)
			fill_pos_pic(ply, (x - 1), y, lst);
		if ((y + 1) < ply->ipiece[0])
			fill_pos_pic(ply, x, (y + 1), lst);
		if ((y - 1) > -1)
			fill_pos_pic(ply, x, (y + 1), lst);
	}
	return (lst);
}
